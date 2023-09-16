QT += widgets

TEMPLATE = lib
DEFINES += CC_PLUGIN2_LIBRARY

CONFIG += c++17
TARGET = ../../../bin/plugin/CC_plugin2
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    pluginio.cpp

HEADERS += \
    ../../interface/plugininterface.h \
    dialog.h \
    pluginio.h

INCLUDEPATH += $$PWD/../../interface \
                $$PWD/../../include

#不加DEPENDPATH会报链接错误因为找不到lib文件
LIBS += -L$$PWD/../../bin/ -lCC_BasePlugin


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dialog.ui
