#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "TrackList.cpp"

TrackList *TLptr;
void MainWindow::on_boxShuffle_checkStateChanged(const Qt::CheckState &arg1)
{
    Shuffle = !Shuffle;
    TLptr->Start(Shuffle, Current);
    this->Display(Current);
    UpdateQueueList();
}

void MainWindow::on_boxLoop_checkStateChanged(const Qt::CheckState &arg1)
{
    Loop = !Loop;

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TLptr = new TrackList();
    Current = 0;
    Shuffle = false;
    Loop = false;
}

void MainWindow::UpdateQueueList()
{
    ui->listQueue->clear();
    for (const auto &track : TLptr->Queue)
    {
        ui->listQueue->addItem(QString::fromStdString(track));
    }
}
void MainWindow::showEvent(QShowEvent *event)
{


    QMainWindow::showEvent(event);
    TLptr->Start(Shuffle, Current);
    this->Display(Current);
    UpdateQueueList();
}


void MainWindow::Display(int curr){
        ui->txtSong->setText(QString::fromStdString(TLptr->GetTrack(curr)));
}
void MainWindow::on_btnNext_clicked()
{
    Current++;
    if (Current >= (int)TLptr->Queue.size()){
        if(Loop == true){
        Current = 0;
        }else{
            Current = TLptr->Queue.size()-1;
        }
    }

    this->Display(Current);
}

void MainWindow::on_btnPrev_clicked()
{

    Current--;
    if (Current < 0){
        if(Loop == true){
        Current = TLptr->Queue.size() - 1;
        }else{
            Current = 0;
        }
    }

    this->Display(Current);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete TLptr;
}




