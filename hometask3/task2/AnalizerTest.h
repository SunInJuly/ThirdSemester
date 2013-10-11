#include "analizer.h"
#include <QtCore/QObject>
#include <QtTest/QtTest>

class AnalizerTest : public QObject

{
   Q_OBJECT
public:
    explicit AnalizerTest(QObject *parent = 0) : QObject(parent) {}
private :
    Analizer * analizer;
    int nulls;
private slots:
    void init ()
    {
        analizer = new Analizer();

    }
    void firstTest()
    {
        analizer->parseFile("test1.txt");
        nulls = analizer->nullElements();
        QVERIFY(nulls == 3);
    }
    void clearTest()
    {
        analizer->clear();
        nulls = analizer->nullElements();
        QVERIFY(nulls == 0);

    }
    void secondTest()
    {


        analizer->parseFile("test2.txt");



        nulls = analizer->nullElements();
        QVERIFY(nulls == 10);

    }

};
