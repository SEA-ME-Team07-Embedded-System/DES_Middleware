#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiracerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pBattery, *pGear, *pMode, *pSetGear, *pSetMode;
    
    long m_battery;
    long m_gear;
    long m_mode;

public:
    PiracerClass();
    ~PiracerClass();

    // Method to get the battery level by calling a Python method
    uint8_t getBattery();
    uint8_t getGear();
    uint8_t getMode();
    void setGear(int gear);
    void setMode(int mode);
};

#endif
