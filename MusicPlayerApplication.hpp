#pragma once
#include "managers/PlaylistManager.hpp"
#include "MusicPlayerFacade.hpp"

using namespace std;

class MusicPlayerApplication
{
private:
    static MusicPlayerApplication* instance;
    vector<Song*> songLibary;
    MusicPlayerApplication(){}
public:
    static MusicPlayerApplication* getInstance()
    {
        if(!instance)
        {
            instance=new MusicPlayerApplication();
        }
        return instance;
    }
    void createSongInLibrary(const string&name,const string& artist,
                                const string& path)
                                {
                                    Song* newSong=new Song(name,artist,path);
                                    songLibary.push_back(newSong);
                                }
    Song* findSongByTitle(const string& title)
    {
        for(Song* s:songLibary)
        {
            if(s->getTitle()==title)
            {
                return s;
            }
        }
        return nullptr;
    }
    void createPlaylist(const string&playlistName)
    {
        PlaylistManager::getInstance()->createPlaylist(playlistName);
    }
    void addSongsToPlaylist(const string& playlistName,
                            const string& songTitle)
                            {
                                Song* s=findSongByTitle(songTitle);
                                if(!s)
                                {
                                    throw runtime_error("Song \"" + songTitle + "\" not found in library.");
                                }
                                PlaylistManager::getInstance()->addSongsToPlaylist(playlistName,s);
                            }
    void connectAudioDevice(DeviceType type)
    {
        MusicPlayerFacade::getInstance()->connectDevice(type);
    }
    void selectPlayerStrategy(StrategyType strategyType)
    {
        MusicPlayerFacade::getInstance()->setPlayStrategy(strategyType);
    }
    void loadPlaylist(const string& playlistName)
    {
        MusicPlayerFacade::getInstance()->loadPlaylist(playlistName);
    }
    void playSingleSong(const string& songTitle)
    {
        Song* song=findSongByTitle(songTitle);
         if (!song) {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->playSong(song);
    }
    void pauseCurrentSong(const string& songTitle)
    {
        Song* song=findSongByTitle(songTitle);
        if(!song)
        {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->pauseSong(song);
    }
    void playAllTrackInPlaylist()
    {
        MusicPlayerFacade::getInstance()->playAllTracks();
    }
    void playPreviousTrackInPlaylist()
    {
        MusicPlayerFacade::getInstance()->playPreviousTrack();
    }
    void queueSongNext(const string& songTitle)
    {
        Song* song = findSongByTitle(songTitle);
        if (!song) 
        {
            throw runtime_error("Song \"" + songTitle + "\" not found.");
        }
        MusicPlayerFacade::getInstance()->enqueueNext(song);
    }
};
MusicPlayerApplication* MusicPlayerApplication::instance=nullptr;