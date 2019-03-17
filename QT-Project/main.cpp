#include "mainwindow.h"
#include <QApplication>
#include<QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(30,30,400,280);
    w.setWindowFlag(Qt::WindowStaysOnTopHint);
    w.setWindowTitle("EB Pearls सुचना !!!");
    w.show();
    return a.exec();
}
