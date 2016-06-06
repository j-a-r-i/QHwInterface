#ifndef TESTDATA_H
#define TESTDATA_H

#include <QtTest>

class TestDataItem : public QObject
{
    Q_OBJECT
private slots:
    void testName();
    void testValue();
    void testCopy1();
    void testCopy2();
};

class TestData: public QObject
{
    Q_OBJECT
private slots:
    void case1();
    void case2();
};

#endif // TESTDATA_H
