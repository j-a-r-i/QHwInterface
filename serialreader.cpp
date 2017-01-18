#include <QSerialPortInfo>
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
        qDebug() << "Error can't open serialport! " << _port->errorString();
        return;
    }

    if (!_port->setBaudRate(RS_SPEED)) {
        qDebug() << "SerialReader setBaudRate " << _port->errorString();
        return;
    }
    if (!_port->setDataBits(QSerialPort::Data8)) {
        qDebug() << "SerialReader setDataBits " << _port->errorString();
        return;
    }
    if (!_port->setParity(QSerialPort::NoParity)) {
        qDebug() << "SerialReader setParity " << _port->errorString();
        return;
    }
    if (!_port->setStopBits(QSerialPort::OneStop)) {
        qDebug() << "SerialReader setStopBits " << _port->errorString();
        return;
    }
    if (!_port->setFlowControl(QSerialPort::NoFlowControl)) {
        qDebug() << "SerialReader setFlowControl " << _port->errorString();
        return;
    }

    connect(_port, SIGNAL(readyRead()),
            this,  SLOT(onRead()));
}

//-----------------------------------------------------------------------------
void SerialReader::ListPorts()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << info.portName() << " - " << info.description();
    }
}

//-----------------------------------------------------------------------------
void SerialReader::onRead()
{
    //qDebug() << "ONREAD";

    if (_port->canReadLine()) {
        QByteArray msg = _port->readLine();
        QString str(msg);
        QStringList list = str.split(QChar(' '));

        qDebug() << "onRead:" << list;

        if (list[0] == QString("m")) {
            bool status = false;
            float t1 = list[2].toUInt(&status, 16) / 16.0f;
            float t2 = list[3].toUInt(&status, 16) / 16.0f;

            data.set(Data::TEMP1, t1);
            data.set(Data::TEMP2, t2);
            //data.set(Data::TEMP3, 0.0f);
            //data.set(Data::TEMP4, 0.0f);

            emit measureReady(data);
        }
    }
}
