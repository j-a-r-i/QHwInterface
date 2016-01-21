QT += core
QT += network
QT += dbus
QT += serialport
QT -= gui

TARGET = QHwInterface
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    mytimer.cpp \
    data.cpp \
    port.cpp \
    spi.cpp \
    rs232.cpp \
    serialreader.cpp

HEADERS += \
    myserver.h \
    mytimer.h \
    data.h \
    config.h \
    port.h \
    spi.h \
    rs232.h \
    serialreader.h

