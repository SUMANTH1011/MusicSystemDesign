#pragma once
#include "IAudioOutputDevice.hpp"
#include "../external/HeadphonesAPI.hpp"
#include "../models/Song.hpp"
using namespace std;
class HeadphoneAdapter:public IAudioOutputDevice
{
private:
    HeadphonesAPI* hp;
public:
    HeadphoneAdapter(HeadphonesAPI*h):hp(h){}
    void playAudio(Song* song) override{
        string payload=song->getTitle()+" by "+song->getArtist();
        hp->playSoundViaJack(payload);
    }
    
};