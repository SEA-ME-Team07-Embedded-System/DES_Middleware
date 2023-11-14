#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiracerClass
{
private:
    PyObject *pBattery, *pSetThrottle, *pSetSteering, *pVehicleModule, *pVehicleClass, *pVehicleInstance;

    long m_battery;

public:
    PiracerClass();
    ~PiracerClass();

    // Method to get the battery level by calling a Python method
    uint8_t getBattery();
    void setThrottle(float throttle);
    void setSteering(float steering);
};

#endif
