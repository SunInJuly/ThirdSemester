#pragma once
#ifndef ANALYZER_H
#define ANALYZER_H
#include <QVector>

#include <QStack>
#include <QPair>

class Analyzer
{
public:
    Analyzer();
    bool answer();
    void setVectors(QVector<QVector<int> > graphVector, QVector<int> robotsVector);
private:
    void nextTop(int top, int currentTop);
    QVector<QVector<int> > oneTopRobots();
    QVector<QVector<int> > graph;
    QVector<int> robots;
    int curClass;
    QStack<int> unvisited;
    QStack<int> visited;
    QVector<QPair<QVector<int> ,QVector<int> > > robotsTops;


};

#endif // ANALYZER_H
