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
    vector<int> Queue;
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
            Queue.push_back(tmp);
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

void Display(const TrackList* tmp, int curr)
{
        cout<<"Now playing: " << tmp->Queue[curr]<<endl;
}



void Start(TrackList* tmp, bool Shuffle, int curr)
{
        if (Shuffle)
        {
            tmp->TLtoQL();
        
            Display(tmp, curr);
        }
        else
        {
            for (int i = static_cast<int>(tmp->tracklist.size()); i >= 0; i--)
            {
                tmp->Queue.push_back(tmp->tracklist[i]);

            }
            Display(tmp,curr);
        }

}
int main(){
		int Current = 0;
        auto* tmp = new TrackList();
        bool Shuffle = false;
        int choice = 0;
        cout<<"Shuffle? 0/1"<<endl;
        cin>>Shuffle;
        Start(tmp, Shuffle, Current);

        while(Current < static_cast<int>(tmp->Queue.size()))
        {
            cout<<"Next/Previous/Close 1/2/0"<<endl;
            cin>>choice;
            switch(choice) {
                case 1:
					Current++;
					if(!Current < static_cast<int>(tmp->Queue.size())
					{
                    Display(tmp,Current);
					}else
					{
						Current = 0;
						Display(tmp,Current);
					}
                    break;
                case 2:
                    Current--;
                    if(!Current > 0)
                    {
                    Display(tmp,Current);
                    }else{
                    Current = static_cast<int>(tmp->Queue.size() - 1;
                    Display(tmp,Current);
					}
                    break;
                default:
                    delete tmp;
                    return 0;

            }
        }




}
