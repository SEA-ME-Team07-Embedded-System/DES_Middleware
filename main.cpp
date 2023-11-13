#include "PiracerClass.hpp"
#include "GamePad.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void fetchAndDisplayData(PiracerClass& piracer) {

    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        uint8_t batteryLevel = piracer.getBattery();
        uint8_t currentGear = piracer.getGear();
        uint8_t currentMode = piracer.getMode();

        std::cout << "Battery Level: " << static_cast<int>(batteryLevel) << std::endl;
        std::cout << "Current Gear: " << static_cast<int>(currentGear) << std::endl;
        std::cout << "Current Mode: " << static_cast<int>(currentMode) << std::endl;
    }
}

void fetchAndDisplayData(GamePad& gamepad) {

    while(1) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));

        gamepad.readControl();

        std::cout << "Throttle: " << gamepad.getThrottle() << std::endl;
        std::cout << "Steering: " << gamepad.getSteering() << std::endl;
        
        if(gamepad.getButtonP)
            std::cout << "Changed Mode: " << gamepad.getButtonP() << std::endl;
        elif(gamepad.getButtonR)
            std::cout << "Changed Mode: " << gamepad.getButtonR() << std::endl;
        elif(gamepad.getButtonN)
            std::cout << "Changed Mode: " << gamepad.getButtonN() << std::endl;
        elif(gamepad.getButtonD)
            std::cout << "Changed Mode: " << gamepad.getButtonD() << std::endl;
    }
}

int main() {
    PiracerClass piracer;
    GamePad gamepad;

    // Create threads for fetching data
    std::vector<std::thread> threads;
    threads.emplace_back(fetchAndDisplayData, std::ref(piracer));
    threads.emplace_back(gamepad_io, std::ref(gamepad));

    // Wait for threads to finish
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
