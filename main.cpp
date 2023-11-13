#include "PiracerClass.hpp"
#include "GamePad.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void fetchAndDisplayData(PiracerClass& piracer) {

    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        uint8_t batteryLevel = piracer.getBattery();
        uint8_t currentGear = piracer.getGear();
        uint8_t currentMode = piracer.getMode();

        std::cout << "Battery Level: " << static_cast<int>(batteryLevel) << std::endl;
        std::cout << "Current Gear: " << static_cast<int>(currentGear) << std::endl;
        std::cout << "Current Mode: " << static_cast<int>(currentMode) << std::endl;
    }
}

void gamepad_io(GamePad& gamepad, PiracerClass& piracer) {

    while(1) {
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        gamepad.readControl();

        std::cout << "Throttle: " << piracer.setThrottle(gamepad.getThrottle()) << std::endl;
        std::cout << "Steering: " << piracer.setSteering(gamepad.getSteering()) << std::endl;

        if(gamepad.getButtonP())
            std::cout << "Changed Mode: " << gamepad.getButtonP() << std::endl;
        else if(gamepad.getButtonR())
            std::cout << "Changed Mode: " << gamepad.getButtonR() << std::endl;
        else if(gamepad.getButtonN())
            std::cout << "Changed Mode: " << gamepad.getButtonN() << std::endl;
        else if(gamepad.getButtonD())
            std::cout << "Changed Mode: " << gamepad.getButtonD() << std::endl;
    }
}

int main() {
    PiracerClass piracer;
    GamePad gamepad;

    // Create threads for fetching data
    std::vector<std::thread> threads;
    //threads.emplace_back(fetchAndDisplayData, std::ref(piracer));
    threads.emplace_back(gamepad_io, std::ref(gamepad), std::ref(piracer));

    // Wait for threads to finish
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
