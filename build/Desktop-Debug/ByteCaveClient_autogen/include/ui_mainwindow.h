/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *AppTitle;
    QPushButton *connectServerBtn;
    QPushButton *sendMessageBtn;
    QTextBrowser *chat;
    QLineEdit *messageLE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AppTitle = new QLabel(centralwidget);
        AppTitle->setObjectName(QString::fromUtf8("AppTitle"));
        AppTitle->setGeometry(QRect(310, 0, 101, 31));
        connectServerBtn = new QPushButton(centralwidget);
        connectServerBtn->setObjectName(QString::fromUtf8("connectServerBtn"));
        connectServerBtn->setGeometry(QRect(500, 70, 141, 41));
        sendMessageBtn = new QPushButton(centralwidget);
        sendMessageBtn->setObjectName(QString::fromUtf8("sendMessageBtn"));
        sendMessageBtn->setGeometry(QRect(500, 270, 141, 41));
        chat = new QTextBrowser(centralwidget);
        chat->setObjectName(QString::fromUtf8("chat"));
        chat->setGeometry(QRect(150, 70, 341, 192));
        messageLE = new QLineEdit(centralwidget);
        messageLE->setObjectName(QString::fromUtf8("messageLE"));
        messageLE->setGeometry(QRect(150, 270, 341, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AppTitle->setText(QCoreApplication::translate("MainWindow", "ByteCave", nullptr));
        connectServerBtn->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        sendMessageBtn->setText(QCoreApplication::translate("MainWindow", "Send Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
