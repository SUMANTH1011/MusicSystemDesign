#pragma once
#include<iostream>
#include<string>
using namespace std;

class WiredSpeakerAPI
{
public:
    void playSoundViaCable(const string &data)
    {
        cout<<"[WiredSpeaker] Playing: "<<data<<endl;
    }
};