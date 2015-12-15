#include <QCoreApplication>
#include "myserver.h"
#include "mytimer.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;
    MyTimer  timer;

    server.start();

    return a.exec();
}

