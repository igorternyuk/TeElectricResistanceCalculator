#-------------------------------------------------
#
# Project created by QtCreator 2017-07-15T14:53:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeCalcElectricResistance
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    doublespinboxdelegate.cpp

HEADERS  += widget.h \
    doublespinboxdelegate.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++14
