#pragma once
#include "IAudioOutputDevice.hpp"
#include "../external/BluetoothSpeakerAPI.hpp"
#include "../models/Song.hpp"

using namespace std;

class BluetoothSpeakerAdapter : public IAudioOutputDevice
{
private:
    BluetoothSpeakerAPI* bs;
public:
    BluetoothSpeakerAdapter(BluetoothSpeakerAPI* b):bs(b){}
    void playAudio(Song* song) override
    {
        string payload=song->getTitle()+" by "+song->getArtist();
        bs->playSoundViaBluetooth(payload);
    }
};