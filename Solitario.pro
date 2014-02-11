#-------------------------------------------------
#
# Project created by QtCreator 2014-01-30T19:47:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Solitario
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    carta.cpp \
    juego.cpp \
    mazoprincipal.cpp \
    nodo.cpp \
    mazoordenado.cpp \
    mazomovimientos.cpp \
    milabel.cpp \
    label.cpp

RESOURCES     = \
    application.qrc

HEADERS  += mainwindow.h \
    carta.h \
    juego.h \
    mazoprincipal.h \
    nodo.h \
    mazoordenado.h \
    mazomovimientos.h \
    milabel.h \
    label.h

FORMS    += mainwindow.ui

RESOURCES +=
