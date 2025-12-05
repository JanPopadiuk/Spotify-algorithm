#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TrackList.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


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
    int Current;
    bool Shuffle;
    bool Loop;
    TrackList *TLptr;
};

#endif // MAINWINDOW_H
