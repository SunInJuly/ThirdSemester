#ifndef COMPUTER_H
#define COMPUTER_H
#include <stdlib.h>
#include "OS.h"
#include "mac.h"
#include "linux.h"
#include "windows.h"
#include <time.h>

/**
  Class represent computers in LAN, hava an OS aboard, which define it security level.
  Can be infected, and attack another computers.
  **/

class Computer
{
public:
    Computer();
    bool refer ();
    bool attacked();
    string sistemType();
    string infectionStatus();
    bool isInfected();
    void setSecurity(int value);
    void setVirusStrength(int value);
private:
    bool infected;
    OS * sistem;
    int virus;
};

#endif // COMPUTER_H
