#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QSerialPort>
#include "data.h"

class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QObject *parent = 0);

    void ListPorts();

signals:
    void measureReady(Data data);

public slots:
    void onRead();

private:
    QSerialPort *_port;
    Data   data;
};

#endif // SERIALREADER_H
