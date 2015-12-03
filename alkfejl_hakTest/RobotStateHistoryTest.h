#ifndef ROBOTSTATEHISTORYTEST_H
#define ROBOTSTATEHISTORYTEST_H

#include <QObject>
#include <QtTest>
#include "RobotStateHistory.h"

/**
 * @brief The alkfejl_hakApplicationTest class
 * Át kellett rendezni a projekt hierarchiát, hogy a unit testeknek megfelelő környezetet alakítsunk ki.
 * @see Ide és a alkfejl_hakLib-be kerülnek a unit testekhez szükséges sorok.
 *
 */

class RobotStateHistoryTest : public RobotStateHistory
{
    Q_OBJECT

/**
 * @see Fontos dokumentáció:Qt Creatorban unit teszt projektet létrehozva kapunk egyből egy kis keretprogramot is, ami elég jól megmutatja, hogyan is kell tesztet készíteni. A unit tesztelés általában azt jelenti, hogy a tesztelendő osztályokat példányosítjuk és mindenféle bemenetekkel bombázzuk, hogy utána ellenőrizzük a reakcióikat. A tesztelendő osztályok általában másik projektből származnak: általában több projektünk van, amiből az egyik a unit tesztek helye, és természetesen látják a többi projekt (pl. library és futtatható alkalmazás külön projektben) osztályait.
 */
public:
    RobotStateHistoryTest();

    /* Adding a set method so we can test the getRobotState() method */
    void RobotStateTest(RobotState *currentST);

    /* historyHasChanged() függvény tesztelése */
    int historyHasChangedTest(const RobotState& state);

    /* */
    int clearScreenTest(const RobotState& state);

    /* */
    int visualizeTest(const RobotState& state);
};



#endif
