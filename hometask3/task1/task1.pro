#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T15:40:09
#
#-------------------------------------------------
QT       += core testlib

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    FileParser.cpp \
    Analyzer.cpp

HEADERS += \
    FileParser.h \
    Analyzer.h \
    ParserTest.h \
    AnalyzerTest.h
