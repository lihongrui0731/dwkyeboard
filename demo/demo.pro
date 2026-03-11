QT += qml quick core gui widgets

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += demo.qrc ../qml.qrc ../content/styles/default/default_style.qrc

# Allow the demo to find the headers and the shared library
INCLUDEPATH += ../include
LIBS += -L$$OUT_PWD/../../lib -ldwkeyboard

# We link libdwkeyboard statically, so we also need to bring its dependency (-lpinyin)
LIBS += -L$$OUT_PWD/../../DWKeyboard/lib/ -lpinyin
