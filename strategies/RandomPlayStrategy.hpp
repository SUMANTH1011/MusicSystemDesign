#pragma once
#include<bits/stdc++.h>
#include "PlayStrategy.hpp"
#include "../models/Song.hpp"
#include "../models/Playlist.hpp"
using namespace std;

class RandomPlayStrategy : public PlayStrategy {
private:
    Playlist* playlist;
    vector<Song*> remainingSongs;
    stack<Song*> history;
public:
    RandomPlayStrategy()
    {
        playlist = nullptr;
        srand((unsigned)time(nullptr));
    }
    void setPlaylist(Playlist* playlist) override
    {
        this->playlist = playlist;
        if(!playlist || playlist->getSize() == 0)
        {
            throw runtime_error("Invalid playlist");
        }
        remainingSongs = playlist->getSongs();
        history = stack<Song*>();
    }
    bool hasNext() override
    {
        return playlist && !remainingSongs.empty();
    }
    Song* next() override{
        if(!playlist || playlist->getSize() == 0)
        {
            throw runtime_error("No playlist loaded or playlist is empty.");
        }
        if(remainingSongs.empty())
        {
            throw runtime_error("No more songs to play.");
        }
        int idx=rand()%remainingSongs.size();
        Song* selecetedSong = remainingSongs[idx];

        swap(remainingSongs[idx], remainingSongs.back());
        remainingSongs.pop_back();
        history.push(selecetedSong);
        return selecetedSong;
    }
    Song* previous() override
    {
        if(history.empty())
        {
            throw std::runtime_error("No previous song available.");
        }
        Song* song=history.top();
        history.pop();
        return song;
    }
    bool hasPrevious() override
    {
        return !history.empty();
    }
};