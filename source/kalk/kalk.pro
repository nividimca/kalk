TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core gui
QT +=printsupport
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets
TARGET = kalk

HEADERS += dati/define/frazione.h \
           dati/define/stringfraz.h \
           dati/define/triplefraz.h \
           gui/define/alert.h \
           gui/define/input.h \
           gui/define/view.h \
           m-c/define/kalk.h \
           m-c/define/check.h \
           m-c/define/checkfraz.h \
           m-c/define/checkstring.h \
           m-c/define/checktriple.h \
           m-c/define/model.h
SOURCES += main.cpp \
           dati/implement/frazione.cpp \
           dati/implement/stringfraz.cpp \
           dati/implement/triplefraz.cpp \
           gui/implement/alert.cpp \
           gui/implement/input.cpp \
           gui/implement/view.cpp \
           m-c/implement/kalk.cpp \
           m-c/implement/check.cpp \
           m-c/implement/checkfraz.cpp \
           m-c/implement/checkstring.cpp \
           m-c/implement/checktriple.cpp \
           m-c/implement/model.cpp
