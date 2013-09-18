#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "computer.h"


class ComputerTest : public QObject
{
    Q_OBJECT
public:
    explicit ComputerTest(QObject *parent = 0) : QObject(parent) {}
private:
    Computer * pc;
private slots:
    void init ()
    {
        pc = new Computer();
    }
    void cleanup()
    {
        delete pc;
    }
    void noInfection()
    {
        QVERIFY(!pc->isInfected());
    }
    void infect()
    {
        do
        {
            pc->attacked();
        }
        while (!pc->isInfected());

        QVERIFY(pc->isInfected());
    }

};
