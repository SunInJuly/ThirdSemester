#include <iostream>
#include "LAN.h"
#include "LANtest.h"
#include "computerTest.h"

using namespace std;

int main()
{
    LANtest test;
    QTest::qExec(&test);
    ComputerTest test1;
    QTest::qExec(&test1);
    char menu = 't';
    LAN * network = new LAN();


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




}

