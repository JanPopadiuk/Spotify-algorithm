#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrackList
{
public:
    vector<int> tracklist;
    vector<int> qList;
    vector<int> Queue;

    TrackList()
    {
        tracklist.push_back(3);
        tracklist.push_back(3);
        tracklist.push_back(2);
        tracklist.push_back(1);
        tracklist.push_back(1);
    }

    void TLtoQL()
    {
        qList.clear();
        Queue.clear();

        for(int i = 0; i < (int)tracklist.size(); i++)
        {
            for(int j = 0; j < tracklist[i]; j++)
            {
                qList.push_back(i);
            }
        }

        Shuffle();
    }

    void Shuffle()
    {
        srand(time(nullptr));
        while(!qList.empty())
        {
            int ran = rand() % qList.size();
            int tmp = qList[ran];

            Queue.push_back(tmp);


            for (int i = qList.size() - 1; i >= 0; i--)
            {
                if (qList[i] == tmp)
                    qList.erase(qList.begin() + i);
            }
        }
    }
};

void Display(int currTrackID)
{
    cout << "Now playing: " << currTrackID << endl;
}

void Start(TrackList* tmp, bool Shuffle, int &curr)
{
    if (Shuffle)
    {
        tmp->TLtoQL();

        curr = 0;
        Display(tmp->Queue[curr]);
    }
    else
    {
        tmp->Queue.clear();


        for (int i = 0; i < (int)tmp->tracklist.size(); i++)
            tmp->Queue.push_back(i);

        curr = 0;
        Display(tmp->Queue[curr]);
    }
}

int main()
{
    int Current = 0;
    auto* tmp = new TrackList();
    bool Shuffle = false;
    int choice = 0;

    cout << "Shuffle? 0/1: ";
    cin >> Shuffle;

    Start(tmp, Shuffle, Current);

    while (true)
    {
        cout << "Next/Previous/Close 1/2/0: ";
        cin >> choice;

        if (choice == 0)
        {
            delete tmp;
            return 0;
        }

        if (choice == 1)  // NEXT
        {
            Current++;
            if (Current >= (int)tmp->Queue.size())
                Current = 0;

            Display(tmp->Queue[Current]);
        }
        else if (choice == 2)  // PREVIOUS
        {
            Current--;
            if (Current < 0)
                Current = tmp->Queue.size() - 1;

            Display(tmp->Queue[Current]);
        }
    }
}
