#ifndef LAN_H
#define LAN_H
#include "computer.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <QList>

using namespace std;

const int size = 6;

/**
  Class LAN represent work of network, consists of computers
  **/


class LAN
{
public:
    LAN();
    void turn();
    bool isWorkable ();
    void logOutStatus();
private:
    void informationFromFile();
    int connections[size][size];
    Computer * users[size];
    void connect (int firstId, int secondId);
    int attacking;
    int attacked;
    bool success;
    QList<int> * infected;


};



#endif // LAN_H
