QT += core
QT += testlib
QT -= gui

CONFIG += c++11

TARGET = UnitTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    testdata.cpp \
    ..\data.cpp

HEADERS += \
    testdata.h \
    ..\data.h
