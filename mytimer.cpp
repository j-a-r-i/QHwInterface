#include "mytimer.h"
#include <QtCore/QDebug>
#include "data.h"
#include "config.h"

//-----------------------------------------------------------------------------
MyTimer::MyTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(onTimer()));

    timer->start(READ_DELAY);
}

//-----------------------------------------------------------------------------
void MyTimer::onTimer()
{
    float diff1 = -0.5 + (qrand() % 11) / 10.0;
    float diff2 = -0.5 + (qrand() % 11) / 10.0;

    float t1 = data.get(Data::TEMP1) + diff1;
    float t2 = data.get(Data::TEMP2) + diff2;

    data.set(Data::TEMP1, t1);
    data.set(Data::TEMP2, t2);

    //qDebug() << "OnTimer";

    emit measureReady(data);
}
