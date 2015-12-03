#include "RobotStateHistory.h"
#include "RobotState.h"

RobotStateHistory::RobotStateHistory()
    : QObject(nullptr), currentState(nullptr)
{
}

void RobotStateHistory::Add(const RobotState& state)
{
    // TODO Add history cleanup function!
    std::unique_ptr<RobotState> newState = std::make_unique<RobotState>();
    newState->CopyFrom(state);
    stateList.append(newState.get());
    currentState = (RobotState*)newState.get(); // This has to be done before moving ownership
    container.push_back(std::move(newState));

    // Összeállítjuk a grafikon számára az adatszerkezetet.
    // Ezek a listák QList<int> típusú listák, amiket direkt arra hozunk létre, hogy a QML elemek
    //  ezekből olvassák ki az adatokat, mivel erre a fenti container nem alkalmas. (Az std::vector
    //  nem támogatja a Qt metaobject rendszerét.)
    clearScreen();

	visualize();

    // Jelezzük a history változását.
    historyHasChanged();
}

int RobotStateHistory::historyHasChanged()
{
    emit historyChanged();
    return 1;
}

int RobotStateHistory::clearScreen()
{
    graphTimestamps.clear();
    graphGyro.clear();
    graphVelocities.clear();
    graphAcceleration.clear();
    return 1;
}

int RobotStateHistory::visualize()
{
    int graphStateNumber = stateList.size() < shownStateNumber ? stateList.size() : shownStateNumber;
    auto it = container.end()-graphStateNumber;
    for(;it!=container.end();++it)
    {
        RobotState *currentState = it->get();
        graphTimestamps.append(currentState->timestamp());
        graphGyro.append(currentState->g());
        graphVelocities.append(currentState->v());
        graphAcceleration.append(currentState->a());
    }

    return 1;
}
