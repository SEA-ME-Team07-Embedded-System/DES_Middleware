// PiracerClient.cpp
#include "PiracerClient.hpp"

PiracerClient::PiracerClient(){
    _battery = 0;
    _gear = 0;
    _mode = 0;
    std::cout << "success init piracer client" << std::endl;
}

PiracerClient::~PiracerClient() {
    std::cout << "close piacer client" << std::endl;
}

void PiracerClient::initVsomeipClient() {
    runtime = CommonAPI::Runtime::get();

    proxy = runtime->buildProxy<PiracerProxy>("local", "Piracer");
    std::cout << "Checking availability!" << std::endl;

    while (!proxy->isAvailable())
        std::this_thread::sleep_for(std::chrono::microseconds(10));
}

void PiracerClient::startSubscribeBattery() {
	proxy->getBatteryAttribute().getValue(callStatus, _battery);
	if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cout << "Error to get attribute Battery value: " << std::endl;
    }
    else {
		std::cout << "Got attribute Battery value: " << int(_battery) << std::endl;
		proxy->getBatteryAttribute().getChangedEvent().subscribe([&](const uint8_t& battery) {
		});
	}
}

void PiracerClient::startSubscribeGear() {
	proxy->getGearAttribute().getValue(callStatus, _gear);
	if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cout << "Error to get attribute Gear value: " << std::endl;
    }
    else {
		std::cout << "Got attribute Gear value: " << int(_gear) << std::endl;
		proxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
		});
	}
}

void PiracerClient::startSubscribeMode() {
	proxy->getModeAttribute().getValue(callStatus, _mode);
	if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cout << "Error to get attribute Mode value: " << std::endl;
    }
    else {
		std::cout << "Got attribute Mode value: " << int(_mode) << std::endl;
		proxy->getModeAttribute().getChangedEvent().subscribe([&](const uint8_t& mode) {
		});
	}
}

void PiracerClient::modeSelectWrapper(uint8_t i) {
    proxy->modeSelect(i, callStatus, returnMessage);
	std::cout << "Got Return Message: '" << returnMessage << "'\n";
}

int main() {
	PiracerClient piracerClient;
	piracerClient.initVsomeipClient();

	piracerClient.startSubscribeBattery();
	piracerClient.startSubscribeMode();
	piracerClient.startSubscribeGear();

    CommonAPI::CallStatus callStatus;

	uint8_t i = 0;

	while (true) {
		std::cout << "Waiting data ... " << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(3));
		
		piracerClient.modeSelectWrapper(i);
        i++;

	}

	return 0;
}