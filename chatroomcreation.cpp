#include "chatroomcreation.h"
#include "ui_chatroomcreation.h"

chatroomCreation::chatroomCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatroomCreation)
{
    ui->setupUi(this);
}

chatroomCreation::~chatroomCreation()
{
    delete ui;
}
