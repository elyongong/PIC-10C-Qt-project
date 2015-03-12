#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QProgressBar>

#include "map.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* Map* town=new Map;
    town->show();*/

    MainWindow* w=new MainWindow;
    w->show();
    return a.exec();
}
