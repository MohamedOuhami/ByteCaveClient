#include "chatroomcreation.h"
#include "ui_chatroomcreation.h"

chatroomCreation::chatroomCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatroomCreation)
{
    ui->setupUi(this);

    // Connect the CLicking accepting button to get the chatroom data
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,[this](){
        getChatroomData();
    });
}

chatroomCreation::~chatroomCreation()
{
    delete ui;
}

// The function that will get called when clicking accept

void chatroomCreation::getChatroomData(){

    // Get the data from the name
    QString name = ui->chatroomNameLE->text();
    QString description = ui->chatroomDescriptionLE->text();

    // Now, we emit the signal to the main window with the 2 data
    emit chatroomCreation::chatroomDataReady(name,description);
}
