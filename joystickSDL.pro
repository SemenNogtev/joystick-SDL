QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    joystickhandler.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    joystickhandler.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += D:/Qt/libs/SDL2/include
LIBS += \
    D:/Qt/libs/SDL2/lib/x64/SDL2.lib \
    D:/Qt/libs/SDL2/lib/x64/SDL2main.lib \
    D:/Qt/libs/SDL2/lib/x64/SDL2test.lib \
#D:/Qt/QtProjects/joystickSDL/SDL2-devel-2.26.5-VC/SDL2-2.26.5/lib/x64/SDL2.dll
#LIBS += -lSDL2
