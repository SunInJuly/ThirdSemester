#include "FileParser.h"

FileParser::FileParser()
{
}

void FileParser::parseFile(string filename)
{
    ifstream file(filename.c_str());
    if (!file)
    {
        cout << "Error! File not found!" << endl;
        return;
    }
    int topsNumber;
    file >> topsNumber;
        file >> robotsNumber;
    file >> connectionsNumber;
    int robot;
    int top1;
    int top2;
    graph.resize(topsNumber);

    for (int i = 0; i < connectionsNumber; i++)
    {
        file >> top1;
        file >> top2;
        matrix.append(QPair<int, int>(top1, top2));
    }
    for (int i = 0; i < robotsNumber; i++)
    {
        file >> robot;
        robots.append(robot);
    }
    file.close();
    for (int i = 0; i < connectionsNumber; i++)
    {
            graph[matrix[i].second].append(matrix[i].first);
            graph[matrix[i].first].append(matrix[i].second);
    }

}


QVector <int> FileParser::getRobotsList()
{
    return robots;
}

QVector <QVector <int> > FileParser::getGraph()
{

    return graph;
}

