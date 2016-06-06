#include "testdata.h"
#include "../data.h"

void TestDataItem::testName()
{
    DataItem item;

    item.setName("foo");

    QCOMPARE(item.getName(), QString("foo"));
}

void TestDataItem::testValue()
{
    DataItem item;

    item.setValue(12.3f);

    QCOMPARE(item.getValue(), 12.3f);
}

void TestDataItem::testCopy1()
{
    DataItem item;
    DataItem other;

    item.set("bar", 12.1f);

    other = item;

    QCOMPARE(other.getName(), QString("bar"));
    QCOMPARE(other.getValue(), 12.1f);
}

void TestDataItem::testCopy2()
{
    DataItem item;

    item.set("bar", 12.1f);

    DataItem other(item);

    QCOMPARE(other.getName(), QString("bar"));
    QCOMPARE(other.getValue(), 12.1f);
}


void TestData::case1()
{
    Data data;

    const float T1 = 10.0f;
    const float T2 = 22.1f;

    data.set(Data::TEMP1, T1);
    data.set(Data::TEMP2, T2);

    QCOMPARE(data.get(Data::TEMP1), T1);
    QCOMPARE(data.get(Data::TEMP2), T2);
}

void TestData::case2()
{
    Data data;

    const float T1 = 10.0f;
    const float T2 = 22.0f;

    data.set(Data::TEMP1, T1);
    data.set(Data::TEMP2, T2);
    data.set(Data::TEMP3, T1);
    data.set(Data::TEMP4, T2);

    QCOMPARE(data.getJson(), QString("{\"T1\":10,\"T2\":22,\"T3\":10,\"T4\":22}"));
}
