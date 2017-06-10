#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T12:11:36
#
#-------------------------------------------------

QT       += core gui opengl sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shapes_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    shapes.cpp \
    db.cpp \
    guictrl.cpp \
    style.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    shapes.h \
    db.h \
    guictrl.h \
    style.h \
    log.h \
    global.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGLU

QMAKE_CXXFLAGS += -std=c++11
