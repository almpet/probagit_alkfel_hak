#include "QtQuickSampleApplicationTest.h"
#include <QtTest/QTest>
#include <QSignalSpy>
#include "RobotStateHistory.h"
#include "RobotStateHistoryTest.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QtQuickSampleApplicationTest::QtQuickSampleApplicationTest(QObject *parent) :
    QObject(parent)
{
}

// Az vizsgáljuk, hogy a RobotStateHistory - historyhaschanged() fügvvénye lefutott-e
void QtQuickSampleApplicationTest::RobotStateHistoryHasChangedTest()
{
    // model init
    RobotStateHistoryTest model;
    RobotState state;

    // array feltöltése
    int arr[] = { 0,1 };
    QVector<int> v(2);
    qCopy(arr, arr+2, v.begin());

    // stream init
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // stream mintaadatokkal való feltöltése
    stream << (qint32) 3;
    stream << Q_INT64_C(123243);
    stream << 1.4;
    stream << 1.0;
    stream << 1.0;
    stream << v;
    stream << (qint8) 1;
    stream << QString::fromUtf8("nincs hiba");

    // state feltöltése a mintaadatokkal
    state.ReadFrom(stream);

    int actual = model.historyHasChangedTest(state);

    // qtest
    QVERIFY2(actual==1 , "Nem futott le a historyHasChanged függvény");
}

/* */
void QtQuickSampleApplicationTest::RobotStateHistoryCleanSreenTest()
{
    // model init
    RobotStateHistoryTest model;
    RobotState state;

    // array feltöltése
    int arr[] = { 0,1 };
    QVector<int> v(2);
    qCopy(arr, arr+2, v.begin());

    // stream init
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // stream mintaadatokkal való feltöltése
    stream << (qint32) 3;
    stream << Q_INT64_C(123243);
    stream << 1.4;
    stream << 1.0;
    stream << 1.0;
    stream << v;
    stream << (qint8) 1;
    stream << QString::fromUtf8("nincs hiba");

    // state feltöltése a mintaadatokkal
    state.ReadFrom(stream);

    int actual = model.clearScreenTest(state);

    // qtest
    QVERIFY2(actual==1 , "Nem futott le a historyHasChanged függvény");
}

/* */
void QtQuickSampleApplicationTest::RobotStateHistoryVisualizeTest()
{
    // model init
    RobotStateHistoryTest model;
    RobotState state;

    // array feltöltése
    int arr[] = { 0,1 };
    QVector<int> v(2);
    qCopy(arr, arr+2, v.begin());

    // stream init
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadWrite);

    // stream mintaadatokkal való feltöltése
    stream << (qint32) 3;
    stream << Q_INT64_C(123243);
    stream << 1.4;
    stream << 1.0;
    stream << 1.0;
    stream << v;
    stream << (qint8) 1;
    stream << QString::fromUtf8("nincs hiba");

    // state feltöltése a mintaadatokkal
    state.ReadFrom(stream);

    int actual = model.visualizeTest(state);

    // qtest
    QVERIFY2(actual==1 , "Nem futott le a historyHasChanged függvény");
}

