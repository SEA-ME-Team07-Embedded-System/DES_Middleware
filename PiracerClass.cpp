#include "PiracerClass.hpp"
#include <iostream>
PiracerClass::PiracerClass()
{
    // Initialize the Python interpreter
    Py_Initialize();    
    pModule = PyImport_ImportModule("seame_piracer.piracer_middleware");
    pClass = PyObject_GetAttrString(pModule, "PiRacer_Middleware");
    pInstance = PyObject_CallObject(pClass, NULL);
}

PiracerClass::~PiracerClass()
{
    // Release Python objects and finalize the Python interpreter
    Py_DECREF(pSetGear);
    Py_DECREF(pSetMode);
    Py_DECREF(pBattery);
    Py_DECREF(pGear);
    Py_DECREF(pMode);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

uint8_t PiracerClass::getBattery()
{
    pBattery = PyObject_CallMethod(pInstance, "get_battery", NULL);
    m_battery = PyLong_AsLong(pBattery);
    return static_cast<uint8_t>(m_battery);
}

uint8_t PiracerClass::getGear()
{
    pGear = PyObject_CallMethod(pInstance, "get_gear", NULL);
    m_gear = PyLong_AsLong(pGear);
    return static_cast<uint8_t>(m_gear);
}

uint8_t PiracerClass::getMode()
{
    pMode = PyObject_CallMethod(pInstance, "get_mode", NULL);
    m_mode = PyLong_AsLong(pMode);
    return static_cast<uint8_t>(m_mode);
}

void PiracerClass::setGear(int gear)
{
    pSetGear = PyObject_CallMethod(pInstance, "gear_select", "i", gear);
    if (pSetGear == NULL) {
        PyErr_Print(); // Print the error details
    }
}

void PiracerClass::setMode(int mode)
{
    pSetMode = PyObject_CallMethod(pInstance, "mode_select", "i", mode);
    if (pSetMode == NULL) {
        PyErr_Print(); // Print the error details
    }
}
