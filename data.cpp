#include "data.h"
#include <QString>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>

const QString Data::TEMP1 = QString("T1");
const QString Data::TEMP2 = QString("T2");
const QString Data::TEMP3 = QString("T3");
const QString Data::TEMP4 = QString("T4");


DataItem::DataItem()
{
}

//-----------------------------------------------------------------------------
DataItem::DataItem(const DataItem& other)
{
    set(other.getName(), other.getValue());
}

DataItem &DataItem::operator=(const DataItem &other)
{
    set(other.getName(), other.getValue());

    return *this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Data::Data()
{
    _list.append(new DataItem(Data::TEMP1, 0.0f));
    _list.append(new DataItem(Data::TEMP2, 0.0f));
    _list.append(new DataItem(Data::TEMP3, 0.0f));
    _list.append(new DataItem(Data::TEMP4, 0.0f));
}

//-----------------------------------------------------------------------------
void Data::set(QString name, float value)
{
    DataItem *iter;

    foreach(iter, _list) {
        if (iter->getName() == QString(name))
        {
            iter->setValue(value);
            break;
        }
    }
}

//-----------------------------------------------------------------------------
float Data::get(QString name)
{
    float ret = 0.0f;
    DataItem *iter;

    foreach(iter, _list) {
        if (iter->getName() == QString(name))
        {
            ret = iter->getValue();
            break;
        }
    }
    return ret;
}


//-----------------------------------------------------------------------------
QString Data::getJson()
{
    QJsonObject obj;
    DataItem *item;

    foreach (item, _list) {
        obj[item->getName()] = item->getValue();
    }

    return QJsonDocument(obj).toJson(QJsonDocument::Compact);
}
