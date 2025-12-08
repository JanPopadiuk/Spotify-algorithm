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
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
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
    QLabel *txtQueue;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *settingswidget;
    QWidget *page_1;
    QListView *listSongList;
    QSpinBox *spinChangeId;
    QSpinBox *spinNewPriority;
    QLabel *label;
    QLabel *label_2;
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
        listQueue->setGeometry(QRect(320, 90, 256, 251));
        txtQueue = new QLabel(centralwidget);
        txtQueue->setObjectName("txtQueue");
        txtQueue->setGeometry(QRect(330, 60, 63, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 90, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 10, 90, 29));
        settingswidget = new QStackedWidget(centralwidget);
        settingswidget->setObjectName("settingswidget");
        settingswidget->setGeometry(QRect(50, 40, 411, 261));
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        listSongList = new QListView(page_1);
        listSongList->setObjectName("listSongList");
        listSongList->setGeometry(QRect(20, 20, 256, 192));
        spinChangeId = new QSpinBox(page_1);
        spinChangeId->setObjectName("spinChangeId");
        spinChangeId->setGeometry(QRect(290, 60, 42, 24));
        spinNewPriority = new QSpinBox(page_1);
        spinNewPriority->setObjectName("spinNewPriority");
        spinNewPriority->setGeometry(QRect(290, 120, 42, 24));
        label = new QLabel(page_1);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 30, 91, 16));
        label_2 = new QLabel(page_1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 100, 81, 16));
        butConfirmChange = new QPushButton(page_1);
        butConfirmChange->setObjectName("butConfirmChange");
        butConfirmChange->setGeometry(QRect(290, 160, 80, 23));
        settingswidget->addWidget(page_1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnNext->setDefault(false);
        settingswidget->setCurrentIndex(0);


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
        txtQueue->setText(QCoreApplication::translate("MainWindow", "Queue:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Main", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
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
