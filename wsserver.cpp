#include "wsserver.h"
#include "config.h"
#include "QtWebSockets/qwebsocket.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QJsonDocument"
#include "QJsonObject"

WSServer::WSServer(QObject *parent) : QObject(parent)
{
    _server = new QWebSocketServer("QtServer",
                                   QWebSocketServer::NonSecureMode);
    if (_server->listen(QHostAddress::AnyIPv4, WS_PORT_NO))
    {
        qDebug() << "WS: listening";

        connect(_server, &QWebSocketServer::newConnection,
                this, &WSServer::onNewConnection);

        connect(_server, &QWebSocketServer::closed,
                this, &WSServer::onClosed);
    }
}

void WSServer::onNewConnection()
{
    QWebSocket *socket = _server->nextPendingConnection();

    qDebug() << "WS: New connection";

    connect(socket, &QWebSocket::textMessageReceived,
            this,   &WSServer::onText);
    connect(socket, &QWebSocket::disconnected,
            this,   &WSServer::onDisconnected);
}

void WSServer::onText(QString msg)
{
    qDebug() << "WS: TEXT:" << msg;

    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());

    QJsonObject obj = doc.object();

    qDebug() << obj["cmd"].toString();
}

void WSServer::onDisconnected()
{
    qDebug() << "WS: Disconnected";
}

void WSServer::onClosed()
{
    qDebug() << "WS: Closed";
    _server->close();
}

