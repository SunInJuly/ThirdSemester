#pragma once
#ifndef ANALIZERTEST_H
#define ANALIZERTEST_H
#include "Analyzer.h"
#include "FileParser.h"
#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QTest>

class AnalyzerTest: public QObject
{
    Q_OBJECT
    private slots:
    void init()
    {
    }
    void cleanup()
    {
    }
    void secondTest()
    {
        parser.parseFile("test2.txt");
        analizer.setVectors(parser.getGraph(), parser.getRobotsList());
        QVERIFY(analizer.answer() == true);
    }

    void firstTest()
    {
        parser.parseFile("test1.txt");
        analizer.setVectors(parser.getGraph(), parser.getRobotsList());
        QVERIFY(analizer.answer() == false);
    }
private:
    Analyzer analizer;
    FileParser parser;


};

#endif // ANALIZERTEST_H
