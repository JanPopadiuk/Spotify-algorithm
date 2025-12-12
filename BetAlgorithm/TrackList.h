#ifndef TRACKLIST_H
#define TRACKLIST_H
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
class TrackList
{
public:
    std::vector<std::pair<int, std::string>> tracklist;
    std::vector<std::string> qList;
    std::vector<std::string> Queue;


     TrackList();
     void TLtoQL();
     void Shuffle();
     std::string GetTrack(int curr);
     void Start(bool shuffle, int &curr);
     void ChangePriority(int songid, int newPriority);
     void TrackList::SaveToFile();

};

#endif // TRACKLIST_H
