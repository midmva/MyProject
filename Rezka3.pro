#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T15:15:14
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rezka3
TEMPLATE = app
INCLUDEPATH += /opt/embedded-widgets-1.1.0/src/
include(/opt/embedded-widgets-1.1.0/src/common/common.pri)
include(/opt/embedded-widgets-1.1.0/src/svglabel/svglabel.pri)

SOURCES += main.cpp\
           widget.cpp \
           spider.cpp \
    svgtoggleswitch/qtsvgtoggleswitch.cpp \
    struct.cpp

HEADERS  += widget.h \
            spider.h \
    svgtoggleswitch/qtsvgtoggleswitch.h \
    struct.h

FORMS    += widget.ui \
            spider.ui \
    struct.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

QT *= svg

RESOURCES += /opt/embedded-widgets-1.1.0/skins/svglabel.qrc \
    res.qrc

