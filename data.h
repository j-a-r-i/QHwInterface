#ifndef DATA_H
#define DATA_H

#include <QMetaType>

class Data
{
public:
    Data();

    float temp1;
    float temp2;

    QString getJson();
};

Q_DECLARE_METATYPE(Data)

#endif // DATA_H
