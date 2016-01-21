#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "data.h"

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

    void start();

signals:

public slots:
    void onConnection();
    void onData();
    void onDisconnected();

    void onMeasure(Data data);

private:
    QTcpServer *server;
    QTcpSocket *socket;
    bool connected;
};

#endif // MYSERVER_H
