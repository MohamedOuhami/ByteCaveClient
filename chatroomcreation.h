#ifndef CHATROOMCREATION_H
#define CHATROOMCREATION_H

#include <QDialog>

namespace Ui {
class chatroomCreation;
}

class chatroomCreation : public QDialog
{
    Q_OBJECT

public:
    explicit chatroomCreation(QWidget *parent = nullptr);
    ~chatroomCreation();

private:
    Ui::chatroomCreation *ui;
};

#endif // CHATROOMCREATION_H
