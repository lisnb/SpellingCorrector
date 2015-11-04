TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    spellingcorrector.cpp \
    edit.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    spellingcorrector.h \
    edit.h

