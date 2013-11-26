#include "Analyzer.h"

Analyzer::Analyzer()
{
    curClass = -1;
}

void Analyzer::setVectors(QVector<QVector<int> > graphVector, QVector<int> robotsVector)
{
    graph = graphVector;
    robots = robotsVector;
}

void Analyzer::nextTop(int top, int currentTop)
{

    for(int i = 0; i < graph[top].size(); i++)
    {
            if((graph[top][i] != currentTop) && (!visited.contains(graph[top][i])) && (!robotsTops[curClass].first.contains(i)))
            {
                    unvisited.push(graph[top][i]);
            }
    }
}
bool Analyzer::answer()
{
    QVector<QVector<int> > vector = oneTopRobots();
    for (int i = 0; i < vector.size(); i++)
    {
            if (vector[i].size() <= 1)
            {
                    return false;
            }
    }
    return true;
}


QVector<QVector<int> > Analyzer::oneTopRobots()
{
    for (int i = 0; i < graph.size(); i++)
    {
            if(!visited.contains(i))
            {
                    curClass++;
                    robotsTops.append(QPair<QVector<int> ,QVector<int> >());
                    unvisited.append(i);

                    while (unvisited.size() != 0)
                    {
                            int temp = unvisited.pop();
                            if (!robotsTops[curClass].first.contains(temp))
                            {
                                    robotsTops[curClass].first.append(temp);
                            }
                            if (robots.contains(temp) && !robotsTops[curClass].second.contains(temp))
                            {
                                    robotsTops[curClass].second.append(temp);
                            }
                            if(graph[temp].size() != 0)
                            {
                                    for(int i = 0; i < graph[temp].size(); i++)
                                    {
                                            nextTop(graph[temp][i], temp);
                                    }
                                    if (!visited.contains(temp))
                                    {
                                            visited.push(temp);
                                    }
                            }
                    }
            }
    }
    QVector<QVector<int> > robot;
    for (int i = 0; i < robotsTops.size(); i++)
    {
            if (robotsTops[i].second.size() != 0)
            {
                robot.append(QVector<int>());
                robot.last() = robotsTops[i].second;
            }
    }
    return robot;
}


