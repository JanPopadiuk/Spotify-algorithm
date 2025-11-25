#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

class TrackList
{
public:
    vector<int> tracklist;
    vector<int> qList;
    queue<int> Queue;
    queue<int> LoopQueue;
    TrackList(){

        tracklist.push_back(3);
        tracklist.push_back(3);
        tracklist.push_back(2);
        tracklist.push_back(1);
        tracklist.push_back(1);
    }
    void TLtoQL()
    {
        for(int i = 0; i < 5;i++)
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
        int tmp = 0;
        int ran = 0;
        while(!qList.empty())
        {
            ran = rand()%qList.size();
            tmp = qList[ran];
            Queue.push(tmp);
            for (int i = static_cast<int>(qList.size()) - 1; i >= 0; i--)
            {
                if (qList[i] == tmp)
                {
                    qList.erase(qList.begin() + i);
                }
            }
        }

    }


};

void Display(const TrackList* tmp)
{
        cout<<"Now playing: " << tmp->Queue.front()<<endl;
}

void Next(TrackList* tmp)
{
    tmp->Queue.pop();
    Display(tmp);
}

void Start(TrackList* tmp, bool Shuffle)
{
        if (Shuffle)
        {
            tmp->TLtoQL();
        tmp->LoopQueue = tmp->Queue;
            Display(tmp);
        }
        else
        {
            for (int i = static_cast<int>(tmp->tracklist.size()); i >= 0; i--)
            {
                tmp->Queue.push(tmp->tracklist[i]);

            }
            Display(tmp);
        }

}
int main(){
        auto* tmp = new TrackList();
        bool Shuffle = false;
        int choice = 0;
        cout<<"Shuffle? 0/1"<<endl;
        cin>>Shuffle;
        Start(tmp, Shuffle);

        while (!tmp->Queue.empty())
        {
            cout<<"Next/Previous/Close 1/2/0"<<endl;
            cin>>choice;
            switch(choice) {
                case 1:
                    Next(tmp);
                    break;
                case 2:
                    //Previous();
                    break;
                default:
                    delete tmp;
                    return 0;

            }
        }




}