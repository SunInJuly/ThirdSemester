#include <QCoreApplication>
#include "AnalizerTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AnalizerTest test;
    QTest::qExec(&test);
    return a.exec();
}
