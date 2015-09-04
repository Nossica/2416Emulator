#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::string parameter = "";

    if (argc > 1) {
        parameter = argv[1];
    }

    MainWindow w(parameter);
    w.show();
    
    return a.exec();
}
