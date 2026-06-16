#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Song.hpp"

using namespace std;

class Playlist
{
private:
    string name;
    vector<Song*>songs;
public:
    Playlist(const string& name):name(name) {}
    string getPlaylistName()
    {
        return name;
    }
    const vector<Song*>& getSongs()
    {
        return songs;
    }
    int getSize()
    {
        return (int)songs.size();
    }
    void addSongToPlaylist(Song* song)
    {
        if(!song)
        {
            throw runtime_error("Invalid song");
            return;
        }
        songs.push_back(song);
    }
};
