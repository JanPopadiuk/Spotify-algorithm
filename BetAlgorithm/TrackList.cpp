#include "TrackList.h"
TrackList::TrackList()
{
    std::ifstream file("songlist.txt");
    std::string LineFromFile;
    if(!file.is_open())
    tracklist.push_back({0,"Couldn't open file"});
    while(getline(file,LineFromFile)) {
        std::string Priority = LineFromFile.substr(0,1);
        int intPriority = stoi(Priority);
        std::string SongName = LineFromFile.substr(2);
        tracklist.push_back({intPriority,SongName});

    }
    file.close();


    // tracklist.push_back({3,"Flashing lights"});
    // tracklist.push_back({3,"Power"});
    // tracklist.push_back({2,"Runaway"});
    // tracklist.push_back({1,"Heartless"});
    // tracklist.push_back({1,"Ghosttown"});
    // tracklist.push_back({2,"On Sight"});
}

void TrackList::TLtoQL()
{
    qList.clear();
    Queue.clear();

    for (auto &t : tracklist)
        for (int j = 0; j < t.first; j++)
            qList.push_back(t.second);

    Shuffle();
}

void TrackList::Shuffle()
{
    srand(time(nullptr));
    while(!qList.empty())
    {
        int ran = rand() % qList.size();
        std::string tmp = qList[ran];

        Queue.push_back(tmp);


        for (int i = qList.size() - 1; i >= 0; i--)
        {
            if (qList[i] == tmp)
                qList.erase(qList.begin() + i);
        }
    }
}

std::string TrackList::GetTrack(int curr)
{
    return Queue[curr];
}


void TrackList::Start(bool shuffle, int &curr)
{
    Queue.clear();

    if (shuffle)
    {
        TLtoQL();
        curr = 0;
        return;
    }

    for (auto &t : tracklist)
        Queue.push_back(t.second);

    curr = 0;
}

void TrackList::ChangePriority(int songid, int newPriority)
{
    tracklist[songid].first = newPriority;
}

void TrackList::SaveToFile(){
    std::ostream file("songlist.txt");
}
