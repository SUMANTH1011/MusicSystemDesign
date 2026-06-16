#pragma once
#include<iostream>
#include<string>

using namespace std;
class Song
{
private:
    string name;
    string artist;
    string filePath;
public:
    Song(string name,string a,string filePath):name(name),artist(a),filePath(filePath){}
    string getTitle()
    {
        return name;
    }
    string getArtist()
    {
        return artist;
    }
    string getFilePath()
    {
        return filePath;
    }
};