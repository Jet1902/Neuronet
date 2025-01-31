#include "mainwindow.h"
#include "Net/cneuronet.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    qDebug() << (int)(10 / 1.1);

    return a.exec();
}
