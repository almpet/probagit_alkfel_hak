#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T22:08:42
#
#-------------------------------------------------

CONFIG += c++14
QMAKE_CXXFLAGS_CXX11    = -std=c++1y

QT       -= gui
QT       += network core
QT += qml quick widgets
QT += serialport

TARGET = alkfejl_hakLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += RobotProxy.cpp \
    RobotState.cpp \
    MainWindowsEventHandling.cpp \
    RobotStateHistory.cpp \
    Communication/Communication.cpp \
    Communication/CommunicationTcpSocket.cpp \
    Communication/CommunicationTcpSocketServer.cpp \
    Communication/CommunicationTcpSocketClient.cpp \
    Simulator/Simulator.cpp \
    Communication/CommunicationSerialPort.cpp \
    StvApplication.cpp

HEADERS += RobotProxy.h \
    RobotState.h \
    MainWindowsEventHandling.h \
    RobotStateHistory.h \
    Communication/Communication.h \
    Communication/CommunicationTcpSocket.h \
    Communication/CommunicationTcpSocketClient.h \
    Communication/CommunicationTcpSocketServer.h \
    Simulator/Simulator.h \
    Communication/CommunicationSerialPort.h \
    StvApplication.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
