#include "btooth.h"
#include "config.h"

BTooth::BTooth(QObject *parent) : QObject(parent)
{
    _agent = new QBluetoothDeviceDiscoveryAgent(this);

    connect(_agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this,   SLOT(deviceFound(QBluetoothDeviceInfo)));

    connect(_agent, SIGNAL(error(QBluetoothDeviceDiscoveryAgent::Error)),
            this,   SLOT(deviceError(QBluetoothDeviceDiscoveryAgent::Error)));

    connect(_agent, SIGNAL(finished()), this, SLOT(scanEnd()));
}

void BTooth::StartScan()
{
    _agent->start();
}

void BTooth::deviceFound(const QBluetoothDeviceInfo &dev)
{
    qDebug() << "Found device: " << dev.name() << '(' << dev.address().toString() << ')';
}

void BTooth::deviceError(const QBluetoothDeviceDiscoveryAgent::Error &err)
{
    switch (err)
    {
    case QBluetoothDeviceDiscoveryAgent::UnsupportedPlatformError:
        qWarning() << "BLE: Unsupported platform";
        break;
    case QBluetoothDeviceDiscoveryAgent::InvalidBluetoothAdapterError:
        qWarning() << "BLE: Invalid adapter";
        break;
    default:
        qWarning() << "BLE: Unknown error";
        break;
    }
}

void BTooth::scanEnd()
{
    qDebug() << "BLE scan ended.";
}
