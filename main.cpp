#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    MainWindow {background-color: rgba(100%, 100%, 100%, 50%)};
//    MainWindow{background-image:url(:images/samsung.jpg)};
//    w.setStyleSheet("background::transparent");
//    w.setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    w.setStyleSheet("background-image:url(:images/samsung1.jpg)");
//    this.setStyleSheet("QMainWindow{background-image:url(:images/samsung.png);background-repeat: no-repeat;}");
    w.show();
    return a.exec();
}
