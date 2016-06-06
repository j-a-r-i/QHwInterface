#include <QCoreApplication>
#include "testdata.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    int stat = 0;
    {
       TestDataItem suite1;
       stat |= QTest::qExec(&suite1);
    }
    {
       TestData suite2;
       stat |= QTest::qExec(&suite2);
    }
    return stat;
}
