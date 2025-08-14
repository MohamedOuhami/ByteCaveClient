#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include <QMainWindow>
#include <string>

using namespace std;

namespace Ui {
class HelloWindow;
}

// This is the HelloWindow, and we're going to transition to the main window after inserting the username
class HelloWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloWindow(QWidget *parent = nullptr);
    ~HelloWindow();
    void transitionToMain(QString &username);

private:
    Ui::HelloWindow *ui;
};

#endif // HELLOWINDOW_H
