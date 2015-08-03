#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T22:40:04
#
#-------------------------------------------------

QT       += core gui

TARGET = 2416Emulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parser.cpp \
    instruction.cpp \
    ram.cpp \
    registers.cpp \
    flags.cpp \
    token.cpp

HEADERS  += mainwindow.h \
    parser.hpp \
    instruction.hpp \
    ram.h \
    registers.h \
    flags.h \
    constants.hpp \
    token.h

FORMS    += mainwindow.ui
