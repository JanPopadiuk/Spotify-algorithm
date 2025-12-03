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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QCheckBox *checkBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(364, 327);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(210, 200, 80, 23));
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
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(190, 150, 78, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 364, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnNext->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        btnPrev->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
        txtNow->setText(QCoreApplication::translate("MainWindow", "Now Playing:", nullptr));
        txtSong->setText(QString());
        boxShuffle->setText(QCoreApplication::translate("MainWindow", "Shuffle", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Loop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
