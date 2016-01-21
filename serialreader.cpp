#include "serialreader.h"
#include "config.h"

//-----------------------------------------------------------------------------
SerialReader::SerialReader(QObject *parent) : QObject(parent)
{
    _port = new QSerialPort(this);

    _port->setPortName(RS_PORT);
    _port->setBaudRate(9600);
    _port->setDataBits(QSerialPort::Data8);
    _port->setParity(QSerialPort::NoParity);
    _port->setStopBits(QSerialPort::OneStop);
    _port->setFlowControl(QSerialPort::NoFlowControl);

    if (_port->open(QIODevice::ReadWrite)) {
    }
    else {
        qDebug() << "Error can't open serialport!";
    }

    connect(_port, SIGNAL(readyRead()),
            this,  SLOT(onRead));
}

//-----------------------------------------------------------------------------
void SerialReader::onRead()
{
    QByteArray msg = _port->readAll();
    QString str(msg);
    QStringList list = str.split(QChar(','));

    qDebug() << list;
}
