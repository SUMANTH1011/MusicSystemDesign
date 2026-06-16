#include "MusicPlayerApplication.hpp"
using namespace std;
int main()
{
    try
    {
        auto application=MusicPlayerApplication::getInstance();

        application->createSongInLibrary("Kesariya",  "Arijit Singh",  "/music/kesariya.mp3");
        application->createSongInLibrary("Chaiyya Chaiyya",   "Sukhwinder Singh",  "/music/chaiyya_chaiyya.mp3");
        application->createSongInLibrary("Tum Hi Ho",  "Arijit Singh",  "/music/tum_hi_ho.mp3");
        application->createSongInLibrary("Jai Ho",  "A. R. Rahman",  "/music/jai_ho.mp3");
        application->createSongInLibrary("Zinda",  "Siddharth Mahadevan",  "/music/zinda.mp3");

        application->createPlaylist("Bollywood Vibes");
        application->addSongsToPlaylist("Bollywood Vibes", "Kesariya");
        application->addSongsToPlaylist("Bollywood Vibes", "Chaiyya Chaiyya");
        application->addSongsToPlaylist("Bollywood Vibes", "Tum Hi Ho");
        application->addSongsToPlaylist("Bollywood Vibes", "Jai Ho");

        application->connectAudioDevice(DeviceType::BLUETOOTH);
         application->playSingleSong("Zinda");
        application->pauseCurrentSong("Zinda");
        application->playSingleSong("Zinda"); 

         cout << "\n-- Sequential Playback --\n";
        application->selectPlayerStrategy(StrategyType::SEQUENTIAL);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTrackInPlaylist();

        cout << "\n-- Random Playback --\n";
        application->selectPlayerStrategy(StrategyType::RANDOM);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTrackInPlaylist();

        cout << "\n-- Custom Queue Playback --\n";
        application->selectPlayerStrategy(StrategyType::CUSTOM_QUEUE);
        application->loadPlaylist("Bollywood Vibes");
        application->queueSongNext("Kesariya");
        application->queueSongNext("Tum Hi Ho");
        application->playAllTrackInPlaylist();

        cout << "\n-- Play Previous in Sequential --\n";
        application->selectPlayerStrategy(StrategyType::SEQUENTIAL);
        application->loadPlaylist("Bollywood Vibes");
        application->playAllTrackInPlaylist();

        application->playPreviousTrackInPlaylist();
        application->playPreviousTrackInPlaylist();
    }
    catch(const exception& error) 
    {
         cerr << "Error: " << error.what() << endl;
    }
    return 0;
}