#-------------------------------------------------
#
# Project created by QtCreator 2023-06-14T14:06:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/libvlc/lib/ -llibVLCQtCore.dll

INCLUDEPATH += $$PWD/libvlc/include
DEPENDPATH += $$PWD/libvlc/include

win32: LIBS += -L$$PWD/libvlc/lib/ -llibVLCQtWidgets.dll

INCLUDEPATH += $$PWD/libvlc/include
DEPENDPATH += $$PWD/libvlc/include
