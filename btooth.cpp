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
    _devices.clear();
    _agent->start();
}

void BTooth::Connect(const QBluetoothAddress &address)
{
    _control = new QLowEnergyController(address, this);

    connect(_control, SIGNAL(serviceDiscovered(QBluetoothUuid)),
            this,     SLOT(serviceDiscovered(QBluetoothUuid)));
    connect(_control, SIGNAL(discoveryFinished()),
            this,     SLOT(serviceScanDone()));
    connect(_control, SIGNAL(error(QLowEnergyController::Error)),
            this,     SLOT(controllerError(QLowEnergyController::Error)));
    connect(_control, SIGNAL(connected()),
            this,     SLOT(deviceConnected()));
    connect(_control, SIGNAL(disconnected()),
            this,     SLOT(deviceDisconnected()));

    _control->connectToDevice();
}

void BTooth::deviceFound(const QBluetoothDeviceInfo &dev)
{
    qDebug() << "Found device: " << dev.name() << '(' << dev.address().toString() << ')';

    _devices.push_back(new BToothDevInfo(dev.name(),
                                         new QBluetoothAddress(dev.address())));
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
    emit scanDone();
}

void BTooth::serviceDiscovered(QBluetoothUuid uuid)
{
}

void BTooth::serviceScanDone()
{
    qDebug() << "BLE service scan ended.";
}

void BTooth::controllerError(QLowEnergyController::Error err)
{
    switch (err) {
    case QLowEnergyController::UnknownError:
        qWarning() << "BLE: Unknown error";
        break;
    case QLowEnergyController::UnknownRemoteDeviceError:
        qWarning() << "BLE: Unknown error in remote device";
        break;
    case QLowEnergyController::NetworkError:
        qWarning() << "BLE: Network error";
        break;
    case QLowEnergyController::InvalidBluetoothAdapterError:
        qWarning() << "BLE: Invalid adapter";
        break;
    case QLowEnergyController::ConnectionError:
        qWarning() << "BLE: Invalid adapter";
        break;
    case QLowEnergyController::AdvertisingError:
        qWarning() << "BLE: Invalid adapter";
        break;
    default:
        qWarning() << "BLE: Invalid error code";
        break;
    }
}

void BTooth::deviceConnected()
{
    qDebug() << "Device connected";
}

void BTooth::deviceDisconnected()
{
    qDebug() << "Device disconnected";
}
