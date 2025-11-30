#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class TrackList
{
public:
    vector<pair<int, string>> tracklist;
    vector<string> qList;
    vector<string> Queue;

    TrackList()
    {
        tracklist.push_back({3,"Flashing lights"});
        tracklist.push_back({3,"Power"});
        tracklist.push_back({2,"Runaway"});
        tracklist.push_back({1,"Heartless"});
        tracklist.push_back({1,"Ghosttown"});
    }

    void TLtoQL()
    {
        qList.clear();
        Queue.clear();

        for(int i = 0; i < (int)tracklist.size(); i++)
        {
            for(int j = 0; j < tracklist[i].first; j++)
            {
                qList.push_back(tracklist[i].second);
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
            string tmp = qList[ran];

            Queue.push_back(tmp);


            for (int i = qList.size() - 1; i >= 0; i--)
            {
                if (qList[i] == tmp)
                    qList.erase(qList.begin() + i);
            }
        }
	}
	
void Display(int curr)
{
    cout << "Now playing: " <<Queue[curr]  << endl;
}

void Start(bool Shuffle, int &curr)
{
    if (Shuffle)
    {
        TLtoQL();

        curr = 0;
        Display( curr);
    }
    else
    {
        Queue.clear();


        for (int i = 0; i < (int)tracklist.size(); i++)
            Queue.push_back(tracklist[i].second);

        curr = 0;
        Display( curr);
    }
}

	void ChangePriority(int songid, int newPriority){
		tracklist[songid].first = newPriority;
	}
};


int main()
{
    int Current = 0;
    auto* tmp = new TrackList();
    bool Shuffle = false;
    int choice = 0;
    bool pChange = false;
    int toChange;
    int newPriority;
    
	for(int i = 0; i < (int)tmp->tracklist.size();i++)
	{
		cout<<i+1 << ": "<< tmp->tracklist[i].second<<" Priority: "<< tmp->tracklist[i].first << endl;
	}
	
	cout<< "Change priority? 0/1: \n";
	cin >> pChange;
	while(pChange){
	
	cout << "Select song number to change: \n";
	cin >> toChange;
	cout<< "Current priority: " <<tmp->tracklist[toChange-1].first << "\nNew priority: ";
	cin >> newPriority;
	tmp->ChangePriority(toChange-1, newPriority);
	for(int i = 0; i < (int)tmp->tracklist.size();i++)
	{
		cout<<i+1 << ": "<< tmp->tracklist[i].second<<" Priority: "<< tmp->tracklist[i].first << endl;
	}
	cout<< "Change priority? 0/1: \n";
	cin >> pChange;
	}
	
    cout << "Shuffle? 0/1: \n";
    cin >> Shuffle;
    

    tmp->Start(Shuffle, Current);

    while (true)
    {
        cout << "Next/Previous/Close 1/2/0: \n";
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

            tmp->Display(Current);
        }
        else if (choice == 2)  // PREVIOUS
        {
            Current--;
            if (Current < 0)
                Current = tmp->Queue.size() - 1;

            tmp->Display(Current);
        }
    }
}
