#include <iostream>
#include "LAN.h"
#include "LANtest.h"
#include "computerTest.h"
#include <QCoreApplication>


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ComputerTest test1;
    QTest::qExec(&test1);
    LANtest test;
    QTest::qExec(&test);

    char menu = 't';
    string file = "network.txt";
    LAN * network = new LAN(file);


    network->logOutStatus();
    /**
      Programm log out sistem status into console
      **/
    do
    {
        cout << "press t to turn and q to quit" << endl;
        cin >> menu;
        if(menu == 'q')
            break;
        network ->turn();

    }
    while (network->isWorkable() && (menu == 't'));

    if(!network->isWorkable())
        cout << "All computers are infected!" << endl;
    std::cout<< "ss";
    return a.exec();

}

