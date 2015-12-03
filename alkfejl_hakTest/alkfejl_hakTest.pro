CONFIG += c++14
QMAKE_CXXFLAGS_CXX11    = -std=c++1y

QT += core testlib
QT -= gui

TARGET = alkfejl_hakTest
CONFIG += console
CONFIG -= app_bundle
CONFIG += testcase

TEMPLATE = app

INCLUDEPATH += $$PWD/../alkfejl_hakLib

SOURCES += main.cpp \
    RobotStateHistoryTest.cpp \
    QtQuickSampleApplicationTest.cpp

HEADERS += \
    RobotStateHistoryTest.h \
    QtQuickSampleApplicationTest.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../alkfejl_hakLib/release/ -lalkfejl_hakLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../alkfejl_hakLib/debug/ -lalkfejl_hakLib
