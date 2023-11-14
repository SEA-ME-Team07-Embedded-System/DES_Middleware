#include "PiracerClass.hpp"
#include <iostream>
PiracerClass::PiracerClass()
{
    Py_Initialize();
    pVehicleModule = PyImport_ImportModule("seame_piracer.vehicles");
    pVehicleClass = PyObject_GetAttrString(pVehicleModule, "PiRacerStandard");
    pVehicleInstance = PyObject_CallObject(pVehicleClass, NULL);

    m_battery = 0;

}

PiracerClass::~PiracerClass()
{
    // Release Python objects and finalize the Python interpreter
    Py_DECREF(pVehicleModule);
    Py_DECREF(pVehicleClass);
    Py_DECREF(pVehicleInstance);
    Py_DECREF(pSetThrottle);
    Py_DECREF(pSetSteering);
    Py_DECREF(pBattery);
    Py_Finalize();
}

uint8_t PiracerClass::getBattery()
{
    pBattery = PyObject_CallMethod(pVehicleInstance, "get_battery", NULL);
    m_battery = PyLong_AsLong(pBattery);
    return static_cast<uint8_t>(m_battery);
}

void PiracerClass::setThrottle(float throttle)
{
    pSetThrottle = PyObject_CallMethod(pVehicleInstance, "set_throttle_percent", "f", throttle);
    if (pSetThrottle == NULL) {
        PyErr_Print(); // Print the error details
    }
}

void PiracerClass::setSteering(float steering)
{
    pSetSteering = PyObject_CallMethod(pVehicleInstance, "set_steering_percent", "f", steering);
    if (pSetSteering == NULL) {
        PyErr_Print(); // Print the error details
    }
}