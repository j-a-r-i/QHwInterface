QT += core
QT += network
QT -= gui

TARGET = QHwInterface
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    mytimer.cpp

HEADERS += \
    myserver.h \
    mytimer.h

