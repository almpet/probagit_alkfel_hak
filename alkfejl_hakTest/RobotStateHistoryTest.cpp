#include "RobotStateHistoryTest.h"

RobotStateHistoryTest::RobotStateHistoryTest()
{
}

int RobotStateHistoryTest::historyHasChangedTest(const RobotState& state)
{
    Add(state);
    // 1-et ad vissza, ha lefutott
    return historyHasChanged();
}

int RobotStateHistoryTest::clearScreenTest(const RobotState& state)
{
    Add(state);
    // 1-et ad vissza, ha lefutott
    return clearScreen();
}

int RobotStateHistoryTest::visualizeTest(const RobotState& state)
{
    Add(state);
    // 1-et ad vissza, ha lefutott
    return visualize();
}
















/*
RobotStateHistoryTest::RobotStateHistoryTest(QObject *parent)
    : RobotStateHistoryTest()
{

}

void alkfejl_hakApplicationTest::myTestValuesTest()
{
    // A QVERIFY2 jelzi az esetleges hibákat a teszt rendszernek,
    //  így ennek segítségével ellenőrizzük a funkciókról,
    //  hogy helyesen működnek-e.
    QVERIFY2(robotstatehistory.add(1,2) == 3, "Az 1+2 még nem megy. :(");
}

QTestDemoTest::QTestDemoTest()
    : calculator()
{
}

void QTestDemoTest::testCase1()
{
    // A QVERIFY2 jelzi az esetleges hibákat a teszt rendszernek,
    //  így ennek segítségével ellenőrizzük a funkciókról,
    //  hogy helyesen működnek-e.
    QVERIFY2(calculator.add(1,2) == 3, "Az 1+2 még nem megy. :(");
}

void QTestDemoTest::testCase2()
{
    // Ezt most direkt nem fog sikerülni.
    QVERIFY2(calculator.add(1,1) == 3, "A hibas unit teszt nem sikerult. :)");
}*/
