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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *AppTitle;
    QPushButton *sendMessageBtn;
    QTextBrowser *chat;
    QLineEdit *messageLE;
    QLabel *label;
    QLabel *label_2;
    QLabel *usernameTag;
    QPushButton *createChatroomBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 370);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AppTitle = new QLabel(centralwidget);
        AppTitle->setObjectName(QString::fromUtf8("AppTitle"));
        AppTitle->setGeometry(QRect(280, 10, 161, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        AppTitle->setFont(font);
        sendMessageBtn = new QPushButton(centralwidget);
        sendMessageBtn->setObjectName(QString::fromUtf8("sendMessageBtn"));
        sendMessageBtn->setGeometry(QRect(460, 270, 81, 41));
        chat = new QTextBrowser(centralwidget);
        chat->setObjectName(QString::fromUtf8("chat"));
        chat->setGeometry(QRect(150, 70, 391, 192));
        messageLE = new QLineEdit(centralwidget);
        messageLE->setObjectName(QString::fromUtf8("messageLE"));
        messageLE->setGeometry(QRect(150, 270, 301, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 20, 131, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 131, 31));
        usernameTag = new QLabel(centralwidget);
        usernameTag->setObjectName(QString::fromUtf8("usernameTag"));
        usernameTag->setGeometry(QRect(150, 330, 161, 18));
        createChatroomBtn = new QPushButton(centralwidget);
        createChatroomBtn->setObjectName(QString::fromUtf8("createChatroomBtn"));
        createChatroomBtn->setGeometry(QRect(580, 60, 131, 26));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AppTitle->setText(QCoreApplication::translate("MainWindow", "ByteCave", nullptr));
        sendMessageBtn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        messageLE->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your message here", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Available chatrooms", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Connected users", nullptr));
        usernameTag->setText(QCoreApplication::translate("MainWindow", "Connected as @", nullptr));
        createChatroomBtn->setText(QCoreApplication::translate("MainWindow", "Create a chatroom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
