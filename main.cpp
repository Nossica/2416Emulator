#include <QtGui/QApplication>
#include "mainwindow.h"

class Parser {
public:

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
