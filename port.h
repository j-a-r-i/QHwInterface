#ifndef PORT_H
#define PORT_H

#include <QString>

class Port
{
public:
    Port();

    void Open(QString filename);

    void Ioctl(int command, void *data);

    void Close();

private:
    int _handle;
};

#endif // PORT_H
