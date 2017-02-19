#include <QCoreApplication>
#include <QtDBus/QtDBus>
#include <QtCore/QDebug>
#include "config.h"
#include "myserver.h"
#include "wsserver.h"
#include "mytimer.h"
#include "serialreader.h"
#include "btooth.h"

BTooth btooth;

//-----------------------------------------------------------------------------
/*void ListServices()
{
    QDBusReply<QStringList> reply = QDBusConnection::systemBus().interface()->registeredServiceNames();
    if (!reply.isValid()) {
        qDebug() << "Error:" << reply.error().message();
        return;
    }
    foreach (QString name, reply.value())
        qDebug() << name;

}*/

//-----------------------------------------------------------------------------
void afterBtScan()
{
    //btooth.Connect();
}

//-----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;

#ifdef SIMULATED
    MyTimer  timer;

    QObject::connect(&timer, SIGNAL(measureReady(Data)),
                     &server, SLOT(onMeasure(Data)));
#else
    SerialReader rs232;

    rs232.ListPorts();

    QObject::connect(&rs232, SIGNAL(measureReady(Data)),
                     &server, SLOT(onMeasure(Data)));
#endif
    server.start();


    WSServer wserver;

    /*if (!QDBusConnection::systemBus().isConnected()) {
        qDebug() << "No dbus session bus!";
    }
    else {
        ListServices();
    }*/


    btooth.StartScan();

    return a.exec();
}

