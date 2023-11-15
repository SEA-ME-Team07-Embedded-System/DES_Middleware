// PiracerClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/PiracerProxy.hpp>

using namespace v1_0::commonapi;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<PiracerProxy<>> piracerProxy =
    	runtime->buildProxy<PiracerProxy>("local", "piracer");
    std::cout << "Checking availability!" << std::endl;

    while (!piracerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;

    while(true) {
        usleep(3 * microsecond);//sleeps for 3 second
        piracerProxy->modeSelect(i, callStatus);
        std::cout << "Send message: " << i << std::endl;
    }
    
    return 0;
}