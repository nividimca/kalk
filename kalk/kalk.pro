TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets
TARGET = kalk

# Input
HEADERS += dati/define/frazione.h \
           dati/define/stringfraz.h \
           dati/define/triplefraz.h \
           gui/define/alert.h \
           gui/define/input.h \
           gui/define/view.h \
           m-c/define/kalk.h \
           m-c/define/logic.h \
           m-c/define/logicfraz.h \
           m-c/define/logicstring.h \
           m-c/define/logictriple.h \
           m-c/define/model.h
SOURCES += main.cpp \
           dati/implement/frazione.cpp \
           dati/implement/stringfraz.cpp \
           dati/implement/triplefraz.cpp \
           gui/implement/alert.cpp \
           gui/implement/input.cpp \
           gui/implement/view.cpp \
           m-c/implement/kalk.cpp \
           m-c/implement/logic.cpp \
           m-c/implement/logicfraz.cpp \
           m-c/implement/logicstring.cpp \
           m-c/implement/logictriple.cpp \
           m-c/implement/model.cpp
