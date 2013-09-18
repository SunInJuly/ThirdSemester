TEMPLATE = app
#CONFIG += console
#CONFIG -= qt

CONFIG   += console qtestlib
QT       += core

SOURCES += main.cpp \
    LAN.cpp \
    computer.cpp \
    OS.cpp \
    mac.cpp \
    linux.cpp \
    windows.cpp

HEADERS += \
    LAN.h \
    computer.h \
    OS.h \
    mac.h \
    linux.h \
    windows.h \
    LANtest.h \
    computerTest.h

