/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnNext;
    QPushButton *btnPrev;
    QLabel *txtNow;
    QLabel *txtSong;
    QCheckBox *boxShuffle;
    QCheckBox *boxLoop;
    QListWidget *listQueue;
    QPushButton *btnUpdateQueueList;
    QPushButton *btnUpdateTrackList;
    QSpinBox *spinChangeId;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinNewPriority;
    QPushButton *butConfirmChange;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(618, 415);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(200, 200, 80, 23));
        btnNext->setCheckable(false);
        btnNext->setFlat(false);
        btnPrev = new QPushButton(centralwidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setGeometry(QRect(40, 200, 80, 23));
        txtNow = new QLabel(centralwidget);
        txtNow->setObjectName("txtNow");
        txtNow->setGeometry(QRect(140, 54, 81, 31));
        txtSong = new QLabel(centralwidget);
        txtSong->setObjectName("txtSong");
        txtSong->setGeometry(QRect(80, 100, 181, 20));
        txtSong->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        txtSong->setStyleSheet(QString::fromUtf8("qproperty-alignment: AlignCenter"));
        boxShuffle = new QCheckBox(centralwidget);
        boxShuffle->setObjectName("boxShuffle");
        boxShuffle->setGeometry(QRect(90, 150, 78, 20));
        boxLoop = new QCheckBox(centralwidget);
        boxLoop->setObjectName("boxLoop");
        boxLoop->setGeometry(QRect(190, 150, 78, 20));
        boxLoop->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        boxLoop->setStyleSheet(QString::fromUtf8(""));
        listQueue = new QListWidget(centralwidget);
        listQueue->setObjectName("listQueue");
        listQueue->setGeometry(QRect(320, 90, 256, 201));
        btnUpdateQueueList = new QPushButton(centralwidget);
        btnUpdateQueueList->setObjectName("btnUpdateQueueList");
        btnUpdateQueueList->setGeometry(QRect(320, 50, 90, 29));
        btnUpdateTrackList = new QPushButton(centralwidget);
        btnUpdateTrackList->setObjectName("btnUpdateTrackList");
        btnUpdateTrackList->setGeometry(QRect(430, 50, 90, 29));
        spinChangeId = new QSpinBox(centralwidget);
        spinChangeId->setObjectName("spinChangeId");
        spinChangeId->setGeometry(QRect(330, 320, 42, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 300, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 300, 81, 16));
        spinNewPriority = new QSpinBox(centralwidget);
        spinNewPriority->setObjectName("spinNewPriority");
        spinNewPriority->setGeometry(QRect(440, 320, 42, 24));
        butConfirmChange = new QPushButton(centralwidget);
        butConfirmChange->setObjectName("butConfirmChange");
        butConfirmChange->setGeometry(QRect(510, 320, 80, 23));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnNext->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        btnPrev->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        txtNow->setText(QCoreApplication::translate("MainWindow", "Now Playing:", nullptr));
        txtSong->setText(QString());
        boxShuffle->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
        boxLoop->setText(QCoreApplication::translate("MainWindow", "Loop", nullptr));
        btnUpdateQueueList->setText(QCoreApplication::translate("MainWindow", "Queue", nullptr));
        btnUpdateTrackList->setText(QCoreApplication::translate("MainWindow", "Track list", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Number of song", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "New priority", nullptr));
        butConfirmChange->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
