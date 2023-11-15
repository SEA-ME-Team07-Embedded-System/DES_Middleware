// PiracerService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "PiracerStubImpl.hpp"

using namespace std;

int main() {
    uint8_t battery = 0;
    uint8_t gear = 0;
    uint8_t mode = 0;

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    
    std::string domain = "local";
    std::string instance = "piracer"; //instance id

    std::shared_ptr<PiracerStubImpl> piracerService = std::make_shared<PiracerStubImpl>();
    while (!runtime->registerService(domain, instance, piracerService)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        battery++;
        gear++;
        mode++;

        piracerService->batteryPublisher(battery);
        piracerService->gearPublisher(gear);
        piracerService->modePublisher(mode);

        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(battery < 100){
            battery = 0;
            gear = 0;
            mode = 0;
        }
    }

    return 0;
 }
