#ifndef QTQUICKSAMPLEAPPLICATIONTEST_H
#define QTQUICKSAMPLEAPPLICATIONTEST_H

#include <QObject>
#include "RobotState.h"
class QtQuickSampleApplicationTest : public QObject
{
    Q_OBJECT
public:
    explicit QtQuickSampleApplicationTest( QObject *parent = 0);

private slots:

    /** @see RobotStateHistory historyhaschanged függvényének a tesztelése */
    void RobotStateHistoryHasChangedTest();

    /** @see RobotStateHistory cleanscreen  függvényének tesztelése */
    void RobotStateHistoryCleanSreenTest();

    /** @see RobotStateHistory visualize függvényének a tesztelése */
    void RobotStateHistoryVisualizeTest();
};

#endif // QTTEST_OTHER_FUNCTIONS_H

