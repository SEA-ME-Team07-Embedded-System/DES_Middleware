#include <CommonAPI/CommonAPI.hpp>
#include "PiracerStubImpl.hpp"
#include <thread>
int main()
{

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "Piracer"; // instance id
    std::string connection = "team07";

    std::shared_ptr<PiracerStubImpl> PiracerService = std::make_shared<PiracerStubImpl>();
    
    while (!runtime->registerService(domain, instance, PiracerService, connection))
    {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Successfully Registered Service!" << std::endl;

    uint8_t battery = 0;
    uint8_t gear = 0;
    uint8_t mode = 0;

    while (true)
    {
        battery++;
        gear++;

        PiracerService->batteryPublisher(battery);
        PiracerService->gearPublisher(gear);
        
        mode = PiracerService->getMode();
        PiracerService->modePublisher(mode);

        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (battery > 100)
        {
            battery = 0;
            gear = 0;
            mode = 0;
        }
        printf("\n");
    }
    return 0;
}
