#ifndef WSSERVER_H
#define WSSERVER_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)

class WSServer : public QObject
{
    Q_OBJECT
public:
    explicit WSServer(QObject *parent = 0);

signals:

public slots:
    void onNewConnection();
    void onClosed();

    void onText(QString msg);
    void onDisconnected();

private:
    QWebSocketServer *_server;
};

#endif // WSSERVER_H
