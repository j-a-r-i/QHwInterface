#include "data.h"
#include <QString>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>

//-----------------------------------------------------------------------------
Data::Data() : temp1(0.0), temp2(0.0)
{

}

//-----------------------------------------------------------------------------
QString Data::getJson()
{
    QJsonObject obj;
    obj["temp1"] = temp1;
    obj["temp2"] = temp2;

    return QJsonDocument(obj).toJson(QJsonDocument::Compact);

    /*QString str;
    QTextStream out(&str);

    out << "{"
        << "\"temp1\":" << temp1 << ","
        << "\"temp2\":" << temp2
        << "}";
    return str;*/
}
