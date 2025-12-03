#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
TrackList::TrackList()
{
    tracklist.push_back({3,"Flashing lights"});
    tracklist.push_back({3,"Power"});
    tracklist.push_back({2,"Runaway"});
    tracklist.push_back({1,"Heartless"});
    tracklist.push_back({1,"Ghosttown"});
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmp = new TrackList();
    Current = 0;
    Shuffle = true;
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    tmp->Start(Shuffle, Current);
    this->Display(Current);
}

void MainWindow::Display(int curr){
        ui->txtSong->setText(QString::fromStdString(tmp->GetTrack(curr)));
}
void MainWindow::on_btnNext_clicked()
{
    Current++;
    if (Current >= (int)tmp->Queue.size())
        Current = 0;

    this->Display(Current);
}

void MainWindow::on_btnPrev_clicked()
{
    Current--;
    if (Current < 0)
        Current = tmp->Queue.size() - 1;

    this->Display(Current);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmp;
}




