#include<bits/stdc++.h>
#include "PlayStrategy.hpp"
#include "../models/Song.hpp"
#include "../models/Playlist.hpp"
using namespace std;

class CustomQueueStrategy : public PlayStrategy {
private:
    Playlist* playlist;
    int currentIndex;
    stack<Song*> prevSongs;
    queue<Song*> nextSongs;
    Song* nextSequential()
    {
        if(playlist->getSize() == 0)
        {
            throw runtime_error("Playlist is empty");
        }
        currentIndex=(currentIndex+1);
        return playlist->getSongs()[currentIndex];
    }
    Song* previousSequential()
    {
        if(playlist->getSize() == 0)
        {
            throw runtime_error("Playlist is empty");
        }
        currentIndex=(currentIndex-1);
        return playlist->getSongs()[currentIndex];
    }
public:
    CustomQueueStrategy():currentIndex(-1),playlist(nullptr) {}
    void setPlaylist(Playlist* playlist) override
    {
     this->playlist=playlist;
     currentIndex=-1;
     while(!nextSongs.empty())
     {
         nextSongs.pop();
     }
        while(!prevSongs.empty())
        {
            prevSongs.pop();
        }
    }
    bool hasNext() override
    {
        return ((currentIndex+1)<playlist->getSize());
    }
    bool hasPrevious() override
    {
        return (currentIndex - 1 >= 0);
    }
    Song* next() override
    {
        if(!playlist || playlist->getSize() == 0)
        {
             throw runtime_error("No playlist loaded or playlist is empty.");
        }
        if(!nextSongs.empty())
        {
            Song* s=nextSongs.front();
            nextSongs.pop();
            prevSongs.push(s);
            auto &list=playlist->getSongs();
            for(int i=0;i<(int)list.size();++i)
            {
                if(list[i]==s)
                {
                    currentIndex=i;
                    break;
                }
            }
            return s;
        }
        return nextSequential();
    }
    Song* previous() override
    {
        if(!playlist || playlist->getSize() == 0)
        {
             throw runtime_error("No playlist loaded or playlist is empty.");
        }
        if(!prevSongs.empty())
        {
            Song* s=prevSongs.top();
            prevSongs.pop();
            nextSongs.push(s);
            auto &list=playlist->getSongs();
            for(int i=0;i<(int)list.size();++i)
            {
                if(list[i]==s)
                {
                    currentIndex=i;
                    break;
                }
            }
            return s;
        }
        return previousSequential();
    }
    void addToNext(Song* song) override{
        if(!song)
        {
            throw runtime_error("Invalid song");
        }
        nextSongs.push(song);
    }
};