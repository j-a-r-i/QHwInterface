#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QTimer>
#include "data.h"

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0);

signals:
    void measureReady(Data data);

public slots:
    void onTimer();

private:
    QTimer *timer;
    Data   data;
};

#endif // MYTIMER_H
