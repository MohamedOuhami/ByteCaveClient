#include "hellowindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the different windows of the app
    // MainWindow w;
    HelloWindow hw;

    // Show the hw first
    hw.show();
    return a.exec();
}
