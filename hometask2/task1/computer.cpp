#include "computer.h"

Computer::Computer()
{
   // srand(static_cast<unsigned int>(time(NULL)));

    int x = rand() % 3;
    switch (x)
    {
    case (0):
        sistem = new Windows ();
        break;
    case(1):
        sistem = new Mac ();
        break;

    case(2):
        sistem = new Linux ();
        break;
    }
    x = rand () % 5;
    if (x == 1)
        infected = true;
    else
        infected = false;


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
    int res = rand() % 8;
    if (res > sistem->securityLevel())
        infected = true;
    return infected;
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
