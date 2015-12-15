#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0);

signals:

public slots:
    void onTimer();

private:
    QTimer *timer;
};

#endif // MYTIMER_H
