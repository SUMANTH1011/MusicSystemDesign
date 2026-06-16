#pragma once
#include "../external/WiredSpeakerAPI.hpp"
#include "IAudioOutputDevice.hpp"
#include "../models/Song.hpp"
using namespace std;
class WiredSpeakerAdapter:public IAudioOutputDevice
{
private:
    WiredSpeakerAPI* ws;
public:
    WiredSpeakerAdapter(WiredSpeakerAPI* w):ws(w){}
    void playAudio(Song* song) override
    {
        string payload=song->getTitle()+" by "+song->getArtist();
        ws->playSoundViaCable(payload);
    }
};