#pragma once
#include<iostream>
#include "../factories/DeviceFactory.hpp"
#include "../enums/DeviceType.hpp"
#include "../device/IAudioOutputDevice.hpp"

using namespace std;

class DeviceManager
{
private:
    static DeviceManager* instance;
    IAudioOutputDevice* currentOutputDevice;
    DeviceManager()
    {
        currentOutputDevice = NULL;
    }
public:
    static DeviceManager* getInstance()
    {
        if(instance==NULL)
        {
            instance = new DeviceManager();
        }
        return instance;
    }
    void connectDevice(DeviceType deviceType)
    {
        if(currentOutputDevice)
        {
            delete currentOutputDevice;
        }
        currentOutputDevice=DeviceFactory::createDevice(deviceType);
        switch(deviceType)
        {
            case DeviceType::BLUETOOTH:
                cout<<"Bluetooth device connected."<<endl;
                break;
            case DeviceType::WIRED:
                cout<<"Wired device connected."<<endl;
                break;
            case DeviceType::HEADPHONES:
                cout<<"Headphones connected."<<endl;
                break;
        }
    }
    IAudioOutputDevice* getOutputDevice()
    {
        if(!currentOutputDevice)
        {
            throw runtime_error("No device connected.");
        }
        return currentOutputDevice;
    }
    bool hasOutputDevice()
    {
        return currentOutputDevice!=NULL;
    }
};
DeviceManager* DeviceManager::instance=NULL;