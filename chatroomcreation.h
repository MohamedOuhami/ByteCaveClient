#ifndef CHATROOMCREATION_H
#define CHATROOMCREATION_H

#include <QDialog>

using namespace std;
namespace Ui {
class chatroomCreation;
}

class chatroomCreation : public QDialog
{
    Q_OBJECT

public:
    explicit chatroomCreation(QWidget *parent = nullptr);
    ~chatroomCreation();


private slots :
    // Get the data when clicking accepted
    void getChatroomData();

// A signal that gets emitted when the user clicks on confirm in the dialog
signals :
    void chatroomDataReady(QString username,QString description);

private:
    Ui::chatroomCreation *ui;
};

#endif // CHATROOMCREATION_H
