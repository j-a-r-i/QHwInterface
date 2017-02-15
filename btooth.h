#ifndef BTOOTH_H
#define BTOOTH_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <list>

class BToothDevInfo : public QObject
{
    Q_OBJECT
public:
    BToothDevInfo(QString name, QBluetoothAddress *address) :
        _name(name),
        _address(address)
    {
    }

    QString GetName() {
        return _name;
    }

    QBluetoothAddress * GteAddress() {
        return _address;
    }

private:
    QString _name;
    QBluetoothAddress *_address;
};


class BTooth : public QObject
{
    Q_OBJECT
public:
    explicit BTooth(QObject *parent = 0);

    void StartScan();
    void Connect(const QBluetoothAddress &address);



signals:
    void scanDone();

public slots:
    void deviceFound(const QBluetoothDeviceInfo &dev);
    void deviceError(const QBluetoothDeviceDiscoveryAgent::Error &err);
    void scanEnd();

    void serviceDiscovered(QBluetoothUuid uuid);
    void serviceScanDone();
    void controllerError(QLowEnergyController::Error err);
    void deviceConnected();
    void deviceDisconnected();

private:
    QBluetoothDeviceDiscoveryAgent *_agent;
    QLowEnergyController *_control;
    std::list<BToothDevInfo*> _devices;
};

#endif // BTOOTH_H
