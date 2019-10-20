#include "mainwindow/mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication MainApplication(argc, argv);
    MainWindow StartMainWindow;

    StartMainWindow.show();

    return MainApplication.exec();
}
