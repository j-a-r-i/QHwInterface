#include "serialreader.h"
#include "config.h"

//-----------------------------------------------------------------------------
SerialReader::SerialReader(QObject *parent) : QObject(parent)
{
    _port = new QSerialPort(this);

    _port->setPortName(RS_PORT);


    if (_port->open(QIODevice::ReadWrite)) {
    }
    else {
        qDebug() << "Error can't open serialport!";
    }

    if (_port->setBaudRate(9600) != 0) {
        qDebug() << "SerialReader setBaudRate " << _port->errorString();
        return;
    }
    if (_port->setDataBits(QSerialPort::Data8) != 0) {
        qDebug() << "SerialReader setDataBits " << _port->errorString();
        return;
    }
    if (_port->setParity(QSerialPort::NoParity) != 0) {
        qDebug() << "SerialReader setParity " << _port->errorString();
        return;
    }
    if (_port->setStopBits(QSerialPort::OneStop) != 0) {
        qDebug() << "SerialReader setStopBits " << _port->errorString();
        return;
    }
    if (_port->setFlowControl(QSerialPort::NoFlowControl) != 0) {
        qDebug() << "SerialReader setFlowControl " << _port->errorString();
        return;
    }

    connect(_port, SIGNAL(readyRead()),
            this,  SLOT(onRead()));
}

//-----------------------------------------------------------------------------
void SerialReader::onRead()
{
    QByteArray msg = _port->readAll();
    QString str(msg);
    QStringList list = str.split(QChar(','));

    qDebug() << list;

    data.set(Data::TEMP1, list[0].toFloat());

    emit measureReady(data);
}
