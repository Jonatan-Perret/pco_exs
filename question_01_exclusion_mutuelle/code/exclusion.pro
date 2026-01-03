QT += core
QT -= gui

LIBS += -lgtest -lpcosynchro
CONFIG += c++17

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp
