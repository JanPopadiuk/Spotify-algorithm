#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Display(int curr);
    void UpdateQueueList();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_btnNext_clicked();
    void on_btnPrev_clicked();

    void on_boxShuffle_checkStateChanged(const Qt::CheckState &arg1);

    void on_boxLoop_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::MainWindow *ui;
    TrackList *tmp;
    int Current;
    bool Shuffle;
    bool Loop;
};

#endif // MAINWINDOW_H
