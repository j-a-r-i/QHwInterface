#include "port.h"
#include <fcntl.h>
#include "config.h"

#ifdef LINUX
  #include <sys/ioctl.h>
#else
  #include <io.h>
  #define open _open
  #define close _close
  #define O_RDWR _O_RDWR
#endif

//-----------------------------------------------------------------------------
Port::Port() : _handle(0)
{
}

//-----------------------------------------------------------------------------
void Port::Open(QString filename)
{
#ifdef LINUX
    _handle = open(filename.toLatin1().constData(), O_RDWR);
    if (_handle < 0) {
        qDebug() << "Error opening file" << filename;
        _handle = 0;
    }
#else
    qDebug() << "opening " << filename;
#endif
}

//-----------------------------------------------------------------------------
void Port::Ioctl(int command, void *data)
{
#ifdef LINUX
    int err;

    if (_handle == 0)
        return;

    err = ioctl(_handle, command, data);
    if (err < 0) {
        qDebug() << "Error ioctl" << command;
    }
#endif
}

//-----------------------------------------------------------------------------
void Port::Close()
{
#ifdef LINUX
    int err;

    if (_handle == 0)
        return;
/*
    err = close(_handle);
    if (err < 0) {
        qDebug() << "Error closing handle" << err;
    }*/
#endif
    _handle = 0;
}
