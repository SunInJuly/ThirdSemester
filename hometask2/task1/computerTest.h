#include <QObject>
#include <QTest>
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
    void unsuccessfullAttack()
    {

        pc->setSecuruty(100);
        pc->setVirusStrength(60);
        pc->attacked();
        QVERIFY(!pc->isInfected());
    }
    void successfulAttack()
    {
        pc->setSecuruty(0);
        pc->setVirusStrength(60);
        pc->attacked();
        QVERIFY(pc->isInfected());
    }
    void infectionCorrect()
    {
        pc->setSecuruty(50);
        pc->setVirusStrength(60);
        pc->attacked();
        QVERIFY(pc->isInfected());
    }

};
