#include "PiracerClass.hpp"
#include "GamePad.hpp"
#include <CommonAPI/CommonAPI.hpp>
#include "PiracerStubImpl.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex mtx;

struct GearState {
    bool gearP = false;
    bool gearR = false;
    bool gearN = false;
    bool gearD = false;
};
void piracer_publish(GearState& gearstate, uint8_t& mode, uint8_t& batteryLevel) {

    // Temporary Gear for enumerate
    uint8_t gear = 0;

    while(true){
        {
            std::lock_guard<std::mutex> lock(mtx);

            // Get Gear
            if(gearstate.gearP) {std::cout << "Gear : P" << std::endl; gear = 0;}
            if(gearstate.gearR) {std::cout << "Gear : R" << std::endl; gear = 1;}
            if(gearstate.gearN) {std::cout << "Gear : N" << std::endl; gear = 2;}
            if(gearstate.gearD) {std::cout << "Gear : D" << std::endl; gear = 3;}
            
            // Get Mode
            mode = PiracerService->getMode();

            // Get Battery
            std::cout << "Battery: " << static_cast<int> (batteryLevel) << std::endl;

            // Publish Data
            PiracerService->batteryPublisher(batteryLevel);
            PiracerService->gearPublisher(gear);
            PiracerService->modePublisher(mode);

        }
        // Sleep to reduce CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void piracer_source(GamePad& gamepad, PiracerClass& piracer, GearState& gearstate, int& mode, uint8_t& batteryLevel)  {

    while(true) {
        gamepad.readControl();
        float throttle = gamepad.getThrottle();
        float steering = gamepad.getSteering();
        {
            std::lock_guard<std::mutex> lock(mtx);

            // Gear change through drive
            gearstate.gearP = (throttle == 0 && steering == 0);
            gearstate.gearR = (throttle < 0);
            gearstate.gearN = (throttle == 0 && steering != 0);
            gearstate.gearD = (throttle > 0);

            // Gear change through GamePad
            if(gamepad.getButtonP()) {gearstate.gearP = true; gearstate.gearR = false; gearstate.gearN = false; gearstate.gearD = false;}
            if(gamepad.getButtonR()) {gearstate.gearP = false; gearstate.gearR = true; gearstate.gearN = false; gearstate.gearD = false;}
            if(gamepad.getButtonN()) {gearstate.gearP = false; gearstate.gearR = false; gearstate.gearN = true; gearstate.gearD = false;}
            if(gamepad.getButtonD()) {gearstate.gearP = false; gearstate.gearR = false; gearstate.gearN = false; gearstate.gearD = true;}

            // Battery change
            batteryLevel = piracer.getBattery();

            // Debug Throttle and Steering
            std::cout << "Throttle: " << throttle << std::endl;
            std::cout << "Steering: " << steering << std::endl;
        }
        piracer.setThrottle(throttle * mode * 0.1);
        piracer.setSteering(steering);

    }
}

int main() {
    // SOME/IP
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "Piracer"; // instance id
    std::shared_ptr<PiracerStubImpl> PiracerService = std::make_shared<PiracerStubImpl>();
    while (!runtime->registerService(domain, instance, PiracerService))
    {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    // Piracer Python Binding
    PiracerClass piracer;
    GamePad gamepad;
    GearState gearstate;
    uint8_t mode = 5;
    uint8_t batteryLevel;

    // Create threads for fetching data
    std::vector<std::thread> threads;
    threads.emplace_back(piracer_source, std::ref(gamepad), std::ref(piracer), std::ref(gearstate), std::ref(mode), std::ref(batteryLevel));
    threads.emplace_back(piracer_publish, std::ref(gearstate), std::ref(mode), std::ref(batteryLevel));



    // Wait for threads to finish
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    
    return 0;
}