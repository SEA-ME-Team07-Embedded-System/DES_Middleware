#include "PiracerClass.hpp"
#include "GamePad.hpp"
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

struct ModeState {
    int modeS = false;
    int modeN = false;
    int modeE = false;
};

void gamepad_io(GamePad& gamepad, PiracerClass& piracer, GearState& gearstate, uint8_t& batteryLevel)  {

    while(true) {
        gamepad.readControl();
        float throttle = gamepad.getThrottle();
        float steering = gamepad.getSteering();

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
        
        // Debug Gear 
        if(gearstate.gearP)
            std::cout << "Gear : P" << std::endl;
        if(gearstate.gearR)
            std::cout << "Gear : R" << std::endl;
        if(gearstate.gearN)
            std::cout << "Gear : N" << std::endl;
        if(gearstate.gearD)
            std::cout << "Gear : D" << std::endl;

        // Debug Battery Level
        batteryLevel = piracer.getBattery();
        std::cout << "Battery: " << static_cast<int> (batteryLevel) << std::endl;

        // Debug Throttle and Steering
        std::cout << "Throttle: " << throttle << std::endl;
        std::cout << "Steering: " << steering << std::endl;
    
        piracer.setThrottle(throttle);
        piracer.setSteering(steering);
    }
}

int main() {

    PiracerClass piracer;
    GamePad gamepad;
    
    GearState gearstate;
    ModeState modestate;
    uint8_t batteryLevel;

    // Create threads for fetching data
    std::vector<std::thread> threads;
    threads.emplace_back(gamepad_io, std::ref(gamepad), std::ref(piracer), std::ref(gearstate), std::ref(batteryLevel));


    // Wait for threads to finish
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    
    return 0;
}