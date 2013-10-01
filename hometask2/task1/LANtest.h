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

private slots:
    void init()
    {
        network = new LAN();
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


};
