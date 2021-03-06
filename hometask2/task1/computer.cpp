#include "computer.h"

Computer::Computer()
{
   // srand(static_cast<unsigned int>(time(NULL)));

    int x = rand() % 3;
    switch (x)
    {
    case (0):
        sistem = new Windows (30);
        break;
    case(1):
        sistem = new Mac (20);
        break;

    case(2):
        sistem = new Linux (50);
        break;
    }
    infected = false;
    set = false;
    virus = rand () % 100 - 10;
}

void Computer::setVirusStrength(int value)
{
    set = false;
    virus = value;
}
bool Computer::isInfected()
{
    return infected;
}
bool Computer::refer()
{
    return infected;
}

bool Computer::attacked ()
{
    if(!set)
        virus = rand () % 100 - 10;
    if (virus > sistem->securityLevel())
        infected = true;
    return infected;
}
void Computer::setSecurity(int value)
{
    sistem->setSecurity(value);
}

string Computer::sistemType()
{
    return sistem->sistemType();
}

string Computer::infectionStatus()
{
    if(infected)
        return " is infected";
    else
        return " not infected";
}
