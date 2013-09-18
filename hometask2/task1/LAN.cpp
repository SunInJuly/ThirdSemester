#include "LAN.h"

LAN::LAN()
{
    srand( (unsigned)time( NULL ) );
    attacking = -1;
    attacked = -1;
    bool success = false;
    int x = rand() % 6;
    do
    {
        users[x].attacked();
    }
    while (!users[x].isInfected());
}

void LAN::turn()
{

    int first = rand () % 6;
    int second;
    do
    {
        second = rand () % 6;
    }
    while (second == first);

    connect(first, second);
    logOutStatus();

}

void LAN::connect(int firstId, int secondId)
{
    success = false;
    attacking = firstId;
    attacked = secondId;
    if (users[firstId].refer())
    {
        if (users[secondId].attacked())
            success = true;


    }

}

void LAN::logOutStatus()
{
    if(attacking != -1)
    {
        cout << "Computer number "  << attacking << " refered to computer number " <<  attacked << endl;
        if (success)
            cout << "Computer " << attacked << " was infected" << endl;
        else
            cout << "No one was infected" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Computer number " << i << " " << users[i].sistemType() << " " << users[i].infectionStatus() << endl;
    }

}

bool LAN::isWorkable()
{
    for (int i = 0; i < size; i++)
    {
        if (!users[i].isInfected())
            return true;
    }
    return false;

}
