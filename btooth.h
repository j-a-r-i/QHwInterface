#ifndef BTOOTH_H
#define BTOOTH_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>

class BTooth : public QObject
{
    Q_OBJECT
public:
    explicit BTooth(QObject *parent = 0);

    void StartScan();

signals:

public slots:
    void deviceFound(const QBluetoothDeviceInfo &dev);
    void deviceError(const QBluetoothDeviceDiscoveryAgent::Error &err);
    void scanEnd();

private:
    QBluetoothDeviceDiscoveryAgent *_agent;
};

#endif // BTOOTH_H
