#include "myserver.h"
#include "config.h"

//-----------------------------------------------------------------------------
MyServer::MyServer(QObject *parent) : QObject(parent), connected(false)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()),
            this,   SLOT(onConnection()));
}

//-----------------------------------------------------------------------------
void MyServer::start()
{
    if (!(server->listen(QHostAddress::Any, PORT_NUMBER))) {
        qDebug() << server->errorString();
    }
}

//-----------------------------------------------------------------------------
void MyServer::onConnection()
{
    qDebug() << "OnConnection";

    socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()),
            this,   SLOT(onData()));

    connect(socket, SIGNAL(disconnected()),
            this,   SLOT(onDisconnected()));

    connected = true;
}

//-----------------------------------------------------------------------------
void MyServer::onData()
{
    qDebug() << "OnData";

    QByteArray arr = socket->readAll();

    qDebug() << "<" << arr.constData() << ">";
}

//-----------------------------------------------------------------------------
void MyServer::onDisconnected()
{
    qDebug() << "OnDisconnected";
    connected = false;
}

//-----------------------------------------------------------------------------
void MyServer::onMeasure(Data data)
{
    qDebug() << data.getJson();

    if (connected) {
        socket->write(data.getJson().toUtf8());
    }
    else {
        qDebug() << "No connection!";
    }
}
