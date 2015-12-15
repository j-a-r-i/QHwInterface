#include "mytimer.h"
#include <iostream>

MyTimer::MyTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(onTimer()));

    timer->start(5000);  // 5 sec
}

void MyTimer::onTimer()
{
    std::cout << "OnTimer" << std::endl;
}
