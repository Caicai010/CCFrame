QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = ../../../bin/CCViewApp
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH +=$$PWD/../../include \
            $$PWD/../../interface \

#不引入lib库会报链接错误因为找不到lib文件
#DEPENDPATH += $$PWD/../../bin/CC_CorePlugin
LIBS += -L$$PWD/../../bin/ -lCC_CorePlugin \
        -L$$PWD/../../bin/ -lCC_ViewPlugin


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
