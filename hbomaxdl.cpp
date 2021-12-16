// this version is a lot more complicated than the python version however it doesn't take an hour to load up and should be fast lol

#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main() {
    // get mpd input
    string mpd;
    cout << "Enter the mpd url: ";
    cin >> mpd;

    // get audio key input
    string ak;
    cout << "Enter the first key (usually audio) [kid:key]: ";
    cin >> ak;

    // get video key input
    string vk;
    cout << "Enter the second key (usually video) [kid:key]: ";
    cin >> vk;

    // create a stringstream named ss
    std::stringstream ss;

    // use it to run some epic commands and delete unused files
    ss << "yt-dlp.exe --downloader aria2c --allow-unplayable-formats \"" << mpd << "\" -o video.mp4 -f \"bestvideo[height<=?1080][tbr>10500]\"";
    system(ss.str().c_str());
    ss << "mp4decrypt.exe --key" << vk << "video.mp4 vd.mp4";
    system(ss.str().c_str());
    remove("video.mp4");

    // repeat a lot hahahah
    ss << "yt-dlp.exe --downloader aria2c --allow-unplayable-formats \"" << mpd << "\" -o english.mp4 -f \"bestaudio[tbr>300][language=en-US]";
    system(ss.str().c_str());
    ss << "mp4decrypt.exe --key" << ak << "english.mp4 en.mp4";
    system(ss.str().c_str());
    remove("english.mp4");

    // .. and more
    ss << "yt-dlp.exe --downloader aria2c --allow-unplayable-formats \"" << mpd << "\" -o spanish.mp4 -f \"bestaudio[tbr>300][language=es-419]";
    system(ss.str().c_str());
    ss << "mp4decrypt.exe --key" << ak << "spanish.mp4 sp.mp4";
    system(ss.str().c_str());
    remove("spanish.mp4");

    // one final time
    ss << "yt-dlp.exe --downloader aria2c --allow-unplayable-formats \"" << mpd << "\" -o portugese.mp4 -f \"bestaudio[tbr>300][language=pt-BR]";
    system(ss.str().c_str());
    ss << "mp4decrypt.exe --key" << ak << "portugese.mp4 pt.mp4";
    system(ss.str().c_str());
    remove("portugese.mp4");
}