#include "analizer.h"


Analizer::Analizer()
{
    cnt = 0;

}

void Analizer::parseFile(string  line)
{
    filename = line;
    ifstream file(line.c_str());
    if(!file)
    {
        cout << "Error! File not found!" << endl;
        return;
    }
    file  >> size;
    array = new int *[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = new int [0];
    }


    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            file >> array[i][j];

        }

    }
    file.close();
}
int Analizer::nullElements()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 0)
                cnt++;

        }

    }
    return cnt;
}
void Analizer::clear()
{
    cnt = 0;
    filename = "";
    size = 0;
}

