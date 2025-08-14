/********************************************************************************
** Form generated from reading UI file 'chatroomcreation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMCREATION_H
#define UI_CHATROOMCREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_chatroomCreation
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *chatroomNameLE;
    QLineEdit *chatroomDescriptionLE;

    void setupUi(QDialog *chatroomCreation)
    {
        if (chatroomCreation->objectName().isEmpty())
            chatroomCreation->setObjectName(QString::fromUtf8("chatroomCreation"));
        chatroomCreation->resize(611, 345);
        buttonBox = new QDialogButtonBox(chatroomCreation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 280, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(chatroomCreation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 30, 311, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(chatroomCreation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 90, 121, 18));
        label_3 = new QLabel(chatroomCreation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 160, 151, 18));
        chatroomNameLE = new QLineEdit(chatroomCreation);
        chatroomNameLE->setObjectName(QString::fromUtf8("chatroomNameLE"));
        chatroomNameLE->setGeometry(QRect(80, 120, 471, 26));
        chatroomDescriptionLE = new QLineEdit(chatroomCreation);
        chatroomDescriptionLE->setObjectName(QString::fromUtf8("chatroomDescriptionLE"));
        chatroomDescriptionLE->setGeometry(QRect(80, 190, 471, 71));

        retranslateUi(chatroomCreation);
        QObject::connect(buttonBox, SIGNAL(accepted()), chatroomCreation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), chatroomCreation, SLOT(reject()));

        QMetaObject::connectSlotsByName(chatroomCreation);
    } // setupUi

    void retranslateUi(QDialog *chatroomCreation)
    {
        chatroomCreation->setWindowTitle(QCoreApplication::translate("chatroomCreation", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("chatroomCreation", "Create your chatroom", nullptr));
        label_2->setText(QCoreApplication::translate("chatroomCreation", "Chatroom name :", nullptr));
        label_3->setText(QCoreApplication::translate("chatroomCreation", "Chatroom description :", nullptr));
        chatroomNameLE->setPlaceholderText(QCoreApplication::translate("chatroomCreation", "Please, enter a name for your chatroom", nullptr));
        chatroomDescriptionLE->setPlaceholderText(QCoreApplication::translate("chatroomCreation", "Please, enter a description for your chatroom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatroomCreation: public Ui_chatroomCreation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMCREATION_H
