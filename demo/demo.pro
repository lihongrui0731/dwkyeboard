QT += qml quick core gui

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Allow the demo to find the headers and the shared library
INCLUDEPATH += ../include
LIBS += -L$$OUT_PWD/../lib -ldwkeyboard
