
#include "LAN.h"

LAN::LAN(string& filename)
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

    informationFromFile(filename);
    users[0]->setSecurity(0);
    users[0]->attacked();
    infected = new QList<int>;
    infected->append(0);

}
void LAN::configureSecurityFromFile(string & filename)
{
    int security;
    int virus;
    ifstream file;
    file.open(filename.c_str());
    for(int i = 0; i < size; i++)
    {
        file >> security;
        file >> virus;
        users[i]->setSecurity(security);
        users[i]->setVirusStrength(virus);
    }

}
void LAN::informationFromFile(string& filename)
{
    ifstream file;
    file.open(filename.c_str());
    int x;
    if(!file)
    {
        cout << "Error! File not found"<< endl;
    }

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
                second = j;
                connect(first, second);
                if (users[i]->isInfected()&&(!infected->contains(j)))
                    infected->append(j);
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
        //users[firstId]->setVirusStrength(rand() % 100);
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
        if (!infected->contains(i))
            return true;
    }
    return false;

}
