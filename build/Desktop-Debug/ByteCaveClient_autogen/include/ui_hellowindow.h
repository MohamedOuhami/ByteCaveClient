/********************************************************************************
** Form generated from reading UI file 'hellowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOWINDOW_H
#define UI_HELLOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *usernameTB;
    QLabel *label_2;
    QPushButton *connectBtn;

    void setupUi(QMainWindow *HelloWindow)
    {
        if (HelloWindow->objectName().isEmpty())
            HelloWindow->setObjectName(QString::fromUtf8("HelloWindow"));
        HelloWindow->resize(800, 363);
        centralwidget = new QWidget(HelloWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 110, 711, 41));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameTB = new QLineEdit(centralwidget);
        usernameTB->setObjectName(QString::fromUtf8("usernameTB"));
        usernameTB->setGeometry(QRect(310, 190, 241, 26));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 190, 151, 18));
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));
        connectBtn->setGeometry(QRect(560, 190, 86, 26));
        HelloWindow->setCentralWidget(centralwidget);

        retranslateUi(HelloWindow);

        QMetaObject::connectSlotsByName(HelloWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HelloWindow)
    {
        HelloWindow->setWindowTitle(QCoreApplication::translate("HelloWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("HelloWindow", "Welcome to V01D's ByteCave", nullptr));
        label_2->setText(QCoreApplication::translate("HelloWindow", "Enter your username : ", nullptr));
        connectBtn->setText(QCoreApplication::translate("HelloWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloWindow: public Ui_HelloWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOWINDOW_H
