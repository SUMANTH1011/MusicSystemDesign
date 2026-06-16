#pragma once

#include <iostream>
#include <string>

class BluetoothSpeakerAPI
{
public:
    void playSoundViaBluetooth(const std::string& data)
    {
        std::cout << "[BluetoothSpeaker] Playing: " << data << std::endl;
    }
};
