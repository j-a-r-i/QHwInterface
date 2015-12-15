#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

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

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // MYSERVER_H
