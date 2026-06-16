#pragma once
#include "PlayStrategy.hpp"
#include "../models/Song.hpp"
#include "../models/Playlist.hpp"
using namespace std;

class SequentialPlayStrategy : public PlayStrategy {
private:
    Playlist* playlist;
    int currentIndex;
public:
    SequentialPlayStrategy():currentIndex(-1),playlist(nullptr){}
    bool hasNext() override
    {
        return ((currentIndex+1)<playlist->getSize());
    }
    void setPlaylist(Playlist* playlist) override
    {
        this->playlist=playlist;
        currentIndex=-1;
    }
    Song* next() override
    {
        if(!playlist || playlist->getSize()==0)
        {
            throw runtime_error("Playlist is empty or not set");
        }
        currentIndex=currentIndex+1;
        return playlist->getSongs()[currentIndex];

    }
    bool hasPrevious() override
    {
        return (currentIndex-1>=0);
    }
    Song *previous() override
    {
        if(!playlist || playlist->getSize()==0)
        {
            throw runtime_error("Playlist is empty or not set");
        }
        currentIndex=currentIndex-1;
        return playlist->getSongs()[currentIndex];
    }
};