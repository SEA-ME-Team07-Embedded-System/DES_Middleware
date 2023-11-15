// PiracerStubImpl.cpp
#include "PiracerStubImpl.hpp"

PiracerStubImpl::PiracerStubImpl() { 
    _battery = 0;
    _gear = 0;
    _mode = 0;

}
PiracerStubImpl::~PiracerStubImpl() { }

// Method Call function
void PiracerStubImpl::modeSelect(const std::shared_ptr<CommonAPI::ClientId> _client,
	int _mode) {
	    std::cout << "Mode Select :" << _mode << std;
}


// Attribute function
void PiracerStubImpl::batteryPublisher(const uint8_t  battery) {
  if (_battery != battery) {
    _battery = battery;
    setBatteryAttribute(_battery);
    std::cout <<  "New Battery Data = " << int(_battery) << "!" << std::endl;
  }
}

void PiracerStubImpl::gearPublisher(const uint8_t  gear) {
  if (_gear != gear) {
    _gear = gear;
    setFdisAttribute(_gear);
    std::cout <<  "New Gear Data = " << int(_gear) << "!" << std::endl;
  }
}

void PiracerStubImpl::rpmPublisher(const uint8_t mode) {
  if (_mode != mode) {
    _mode = mode;
    setRpmAttribute(_mode);
    std::cout <<  "New Mode Data = " << int(_mode) << "!" << std::endl;
  }
}