#include "data.h"
#include <QString>
#include <QTextStream>

//-----------------------------------------------------------------------------
Data::Data() : temp1(0.0), temp2(0.0)
{

}

//-----------------------------------------------------------------------------
QString Data::getJson()
{
    QString str;
    QTextStream out(&str);

    out << "{"
        << "\"temp1\":" << temp1 << ","
        << "\"temp2\":" << temp2
        << "}";
    return str;
}
