#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T20:54:49
#
#-------------------------------------------------

QT       += core

QT += testlib

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    windows.cpp \
    OS.cpp \
    mac.cpp \
    linux.cpp \
    LAN.cpp \
    computer.cpp

HEADERS += \
    windows.h \
    OS.h \
    mac.h \
    linux.h \
    LANtest.h \
    LAN.h \
    computerTest.h \
    computer.h

