#include "myserver.h"
#include <iostream>

//-----------------------------------------------------------------------------
MyServer::MyServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()),
            this,   SLOT(onConnection()));
}

//-----------------------------------------------------------------------------
void MyServer::start()
{
    if (!(server->listen(QHostAddress::Any, 8001))) {
        std::cout << server->errorString().toStdString() << std::endl;
    }
}

//-----------------------------------------------------------------------------
void MyServer::onConnection()
{
    std::cout << "OnConnection" << std::endl;

    socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()),
            this,   SLOT(onData()));

    connect(socket, SIGNAL(disconnected()),
            this,   SLOT(onDisconnected()));
}

//-----------------------------------------------------------------------------
void MyServer::onData()
{
    std::cout << "OnData" << std::endl;

    QByteArray arr = socket->readAll();

    std::cout << "<" << arr.constData() << ">" << std::endl;
}

//-----------------------------------------------------------------------------
void MyServer::onDisconnected()
{
    std::cout << "OnDisconnected" << std::endl;
}
