#ifndef ANALIZER_H
#define ANALIZER_H

#include <string>
#include <iostream>
#include <fstream>

 using namespace std;

class Analizer
{
public:
    Analizer();
    int nullElements();
    void parseFile(string line);
    void clear();
private:
    int cnt;

    int size;
    int ** array;
    string filename;

};

#endif // ANALIZER_H

