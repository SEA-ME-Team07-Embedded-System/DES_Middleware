// PiracerService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "PiracerStubImpl.hpp"

using namespace std;

int main() {
    CommonAPI::Runtime::setProperty("LogContext", "Piracer");
    CommonAPI::Runtime::setProperty("LogApplication", "Piracer");
    CommonAPI::Runtime::setProperty("LibraryBase", "Piracer");

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "Piracer"; //instance id
    std::string connection = "team07";

    std::shared_ptr<PiracerStubImpl> PiracerService = std::make_shared<PiracerStubImpl>();
    
    while (!runtime->registerService(domain, instance, PiracerService, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
    

    // Logic here
    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
 }