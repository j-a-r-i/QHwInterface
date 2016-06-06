#ifndef DATA_H
#define DATA_H

#include <QMetaType>
#include <QString>
#include <QList>

//-----------------------------------------------------------------------------
class DataItem
{
public:
    DataItem();
    DataItem(const DataItem& other);
    DataItem(const QString name, float value) {
        set(name, value);
    }

    DataItem &operator=(const DataItem &other);

    QString getName() const {
        return _name;
    }

    void set(const QString name, float value) {
        _name = name;
        _value = value;
    }

    void setName(const char* name) {
        _name = name;
    }

    float getValue() const {
        return _value;
    }

    void setValue(float value) {
        _value = value;
    }

private:
    QString _name;
    float _value;
};

//-----------------------------------------------------------------------------
class Data
{
public:
    static const QString TEMP1;
    static const QString TEMP2;
    static const QString TEMP3;
    static const QString TEMP4;

    Data();

    void set(QString name, float value);

    float get(QString name);

    QString getJson();

private:
    QList<DataItem*> _list;
};

#endif // DATA_H
