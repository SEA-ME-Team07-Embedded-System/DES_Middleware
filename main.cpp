#include "PiracerClass.hpp"
#include <iostream>

int main() {
    // Create an instance of PiracerClass
    PiracerClass piracer;
    int i = 0;
    // Example usage of PiracerClass methods
    uint8_t batteryLevel = piracer.getBattery();
    uint8_t currentGear = piracer.getGear();
    uint8_t currentMode = piracer.getMode();

   while(i < 100){
	i++;
        std::cout << "Battery Level: " << (int) batteryLevel << std::endl;
        std::cout << "Current Gear: " << (int) currentGear << std::endl;
        std::cout << "Current Mode: " << (int) currentMode << std::endl;
    }

    return 0;
}
