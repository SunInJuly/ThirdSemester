
#include "LAN.h"

LAN::LAN()
{
    srand( (unsigned)time( NULL ) );
    attacking = -1;
    attacked = -1;
    success = false;
    int x = rand() % size;
    for(int i = 0; i < size; i++)
    {
        users[i] = new Computer();
    }
    do
    {
        users[x]->attacked();
    }
    while (!users[x]->isInfected());
    infected = new QList<int>;
    infected->append(x);
    informationFromFile();
}

void LAN::informationFromFile()
{
    ifstream file;
    file.open("network.txt");
    int x;


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file >> x;
            connections[i][j] = x;

        }

    }

}


void LAN::turn()
{
    int first, second;
    for (int i = 0; i < infected->size(); i++)
    {
        first = infected->operator [](i);

        for (int j = 0; j < size; j++)
         {
            if(connections[first][j] != 0)
            {
                second = i;
                connect(first, second);
                if (users[i]->isInfected())
                    infected->append(i);
            }
        }
    }

    logOutStatus();
}

void LAN::connect(int firstId, int secondId)
{
    success = false;
    attacking = firstId;
    attacked = secondId;
    if (users[firstId]->refer())
    {
        users[firstId]->setVirusStrength(rand() % 100);
        if (users[secondId]->attacked())
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
        cout << "Computer number " << i << " " << users[i]->sistemType() << " " << users[i]->infectionStatus() << endl;
    }

}

bool LAN::isWorkable()
{
    for (int i = 0; i < size; i++)
    {
        if (!users[i]->isInfected())
            return true;
    }
    return false;

}
