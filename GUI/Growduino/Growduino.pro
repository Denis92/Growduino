#-------------------------------------------------
#
# Project created by QtCreator 2015-09-23T21:01:56
#
#-------------------------------------------------
QT += core gui serialport widgets

TARGET = Growduino
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    growduino.cpp \
    watercalc.cpp \
    addeventform.cpp \
    addsensform.cpp

HEADERS  += mainwindow.h \
    growduino.h \
    watercalc.h \
    addeventform.h \
    addsensform.h

FORMS    += mainwindow.ui \
    addeventform.ui \
    addsensform.ui

DISTFILES +=

RESOURCES += \
    ../res.qrc

