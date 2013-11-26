#pragma once
#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QVector>
#include <QPair>
#include <fstream>
#include <iostream>
using namespace std;

class FileParser
{
public:
    FileParser();
    void parseFile(string filename);
    QVector <int> getRobotsList();
    QVector <QVector<int> > getGraph();
private:
    QVector<int> robots;
    QVector<QVector<int> > graph;
    QVector<QPair <int, int> > matrix;
    int connectionsNumber;
    int robotsNumber;

};

#endif // FILEPARSER_H
