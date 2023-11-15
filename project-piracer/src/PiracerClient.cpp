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
    
    int i = 0;

    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
	piracerProxy->modeSelect(i, callStatus);
        std::cout << "Send message: " << i << std::endl;
	i++;
    }
    
    return 0;
}
