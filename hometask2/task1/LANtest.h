#include <QObject>
#include <QTest>
#include "LAN.h"


class LANtest : public QObject
{
    Q_OBJECT
public:
    explicit LANtest(QObject *parent = 0) : QObject(parent) {}
private:
    LAN * network;
    LAN * network2;

private slots:
    void init()
    {

        string name = "network.txt";
        network = new LAN(name);
        string file = "security.txt";
        network->configureSecurityFromFile(file);
    }
    void cleanup()
    {
        delete network;
    }
    void workableTest()
    {
        QVERIFY(network->isWorkable());
    }
    void turnTest()
    {
        network->turn();
        QVERIFY(network->isWorkable());
    }
    void infectionTest()
    {

        for (int i = 0; i < 5; i++)
        {
            network->turn();
        }
        QVERIFY(network->isWorkable());

    }
    void infectionTest2()
    {
        string security = "security2.txt";
        network->configureSecurityFromFile(security);
            network->turn();
        QVERIFY(!network->isWorkable());
    }


};
