#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QSerialPort>

class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QObject *parent = 0);

signals:

public slots:
    void onRead();

private:
    QSerialPort *_port;
};

#endif // SERIALREADER_H
