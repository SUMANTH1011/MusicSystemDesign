#pragma once
#include<iostream>
#include "../device/IAudioOutputDevice.hpp"
#include "../device/BluetoothSpeakerAdapter.hpp"
#include "../device/WiredSpeakerAdapter.hpp"
#include "../device/HeadphoneAdapter.hpp"
#include "../enums/DeviceType.hpp"

using namespace std;
class DeviceFactory
{
public:
    static IAudioOutputDevice* createDevice(DeviceType type)
    {
        if(type==DeviceType::BLUETOOTH)
        {
            return new BluetoothSpeakerAdapter(new BluetoothSpeakerAPI());
        }
        else if(type==DeviceType::WIRED)
        {
            return new WiredSpeakerAdapter(new WiredSpeakerAPI());
        }
        else if(type==DeviceType::HEADPHONES)
        {
            return new HeadphoneAdapter(new HeadphonesAPI());
        }
        else
        {
            throw invalid_argument("Invalid device type.");
        }
    }
};
