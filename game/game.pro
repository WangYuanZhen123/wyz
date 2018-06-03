#-------------------------------------------------
#
# Project created by QtCreator 2018-06-03T08:49:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    icon.cpp \
    rpgobj.cpp \
    player.cpp \
    world.cpp

HEADERS  += mainwindow.h \
    icon.h \
    rpgobj.h \
    player.h \
    world.h

FORMS    += mainwindow.ui
