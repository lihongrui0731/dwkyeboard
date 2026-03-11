QT += qml quick core gui widgets

CONFIG += c++11

SOURCES += main.cpp

RESOURCES += demo.qrc ../qml.qrc ../content/styles/default/default_style.qrc

# Allow the demo to find the headers and the shared library
INCLUDEPATH += ../include
LIBS += -L$$OUT_PWD/../lib -ldwkeyboard

# We link libdwkeyboard statically, so we also need to bring its dependency (-lpinyin)
LIBS += -L$$OUT_PWD/../DWKeyboard/lib/ -lpinyin

# Copy the pinyin dictionary to the demo binary output directory so PinyinDecoderService can initialize
copy_dict.target = data/pinyin/dict_pinyin.dat
copy_dict.commands = $(MKDIR) data/pinyin && $(COPY) $$PWD/../3rdparty/pinyin/data/dict_pinyin.dat data/pinyin/dict_pinyin.dat
QMAKE_EXTRA_TARGETS += copy_dict
POST_TARGETDEPS += data/pinyin/dict_pinyin.dat
