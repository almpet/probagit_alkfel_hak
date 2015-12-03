#pragma once
#ifndef COMMUNICATIONSERIALPORT_H
#define COMMUNICATIONSERIALPORT_H
#include "Communication/Communication.h"
#include <QtSerialPort/QSerialPort>

// http://doc.qt.io/qt-5/qtserialport-index.html
// http://doc.qt.io/qt-5/qserialport.html
// http://doc.qt.io/qt-5/qiodevice.html#readyRead
// http://doc.qt.io/qt-5/qtserialport-examples.html

/**
 * @brief Soros port kommunikáció
 */

/**
 * @brief @see Jól megfigyelhető itt a FACADE design pattern. A facade egy egyszerűbben használható (vagy egyéb szempontból más) interfészt biztosít egy elfedett osztály, osztály halmaz vagy függvények felé.
 * @see Nem csak ennél a Tcp-s headereknél is észrevehető ugyanez. A Communication osztályt elrejtük, és a használandó függvényeket valósítjuk meg ebben az osztályban. A facade tehát belül aggregál egy másik, összetettebb rendszert, vagy interfészt.
 */
class CommunicationSerialPort : public Communication
{
public:
    CommunicationSerialPort(QString portName,
            qint32 baudRate,
            QSerialPort::DataBits dataBits,
            QSerialPort::Parity parity,
            QSerialPort::StopBits stopBits);
    virtual ~CommunicationSerialPort() = default;

    virtual void connect();
    virtual bool isConnected() const override;

protected:
    virtual void sendBufferContent() override;

private:
    QSerialPort serialPort;

private slots:
    // Forwards signal to errorOccurred.
    void handleError(QSerialPort::SerialPortError error);

};

#endif // COMMUNICATIONSERIALPORT_H
