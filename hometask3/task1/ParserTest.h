#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <fstream>
#include <iostream>
#ifndef PARSERTEST_H
#define PARSERTEST_H

#include "FileParser.h"

using namespace std;

class ParserTest: public QObject
{
    Q_OBJECT
    private slots:
            void init()
            {
                vector = QVector<int> () << 1 << 2;
                graph.resize(4);
                graph[0] = QVector<int> () << 1 << 3;
                graph[1] = QVector<int> () << 0 << 2;
                graph[2] = QVector<int> () << 1;
                graph[3] = QVector<int> () << 0;
            }
            void cleanup()
            {
            }
            void firstTest()
            {
                parser.parseFile("test1.txt");
                QVERIFY(parser.getRobotsList() == vector);
                QVector<QVector<int> > graph1 =  parser.getGraph();
                QVERIFY(graph1 == graph);
            }
private:
            QVector<int> vector;
            QVector<QVector<int> > graph;
            FileParser parser;


};

#endif // PARSERTEST_H
