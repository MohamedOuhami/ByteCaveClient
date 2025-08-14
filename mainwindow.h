#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bytecaveclient.h>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString username,QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ByteCaveClient *client = nullptr;
    void OnSendButtonClicked();
    void OnCreateChatroomButtonClicked();
    QString username;
};
#endif // MAINWINDOW_H
