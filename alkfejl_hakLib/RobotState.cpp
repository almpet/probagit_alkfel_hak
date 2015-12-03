#include <QDebug>
#include "RobotState.h"

std::map<int,QString> RobotState::statusNames;

RobotState::RobotState()
{
    initStatusNames();
}

RobotState::RobotState(Status status, qint64 timestamp,
    float x, float v, float a,QVector<int> g, qint8 light, QString error)
    : _status(status), _timestamp(timestamp), _x(x), _v(v), _a(a), _g(g), _light(light), _error(error)
{
    initStatusNames();
}

void RobotState::initStatusNames()
{
    if (statusNames.empty())
    {
        // Még nincsen inicializálva.
        statusNames[(int)Status::Accelerate] = QString("Gyorsítás");
        statusNames[(int)Status::Default] = QString("Alap");
        statusNames[(int)Status::Reset] = QString("Reset");
        statusNames[(int)Status::Stopping] = QString("Megállás");
        statusNames[(int)Status::Error] = QString("Error");
        statusNames[(int)Status::SelfTest] = QString("Öntesztelés");

    }
}

QString RobotState::getStatusName() const
{
    auto it = statusNames.find((int)_status);
    Q_ASSERT(it != statusNames.end());
    return it->second;
}

void RobotState::WriteTo(QDataStream& stream) const
{
    stream << (qint32)_status;
    stream << _timestamp;
    stream << _x;
    stream << _v;
    stream << _a;
    stream << _g;
    stream << _light;
    stream << _error;
}

void RobotState::ReadFrom(QDataStream& stream)
{
    qint32 tmpQint32;
    stream >> tmpQint32;
    _status = (Status)tmpQint32;
    stream >> _timestamp;
    stream >> _x;
    stream >> _v;
    stream >> _a;
    stream >> _g;
    stream >> _light;
    stream >> _error;
}

void RobotState::CopyFrom(const RobotState &other)
{
    _status = other._status;
    _timestamp = other._timestamp;
    _x = other._x;
    _v = other._v;
    _a = other._a;
    _g = other._g;
    _light = other._light;
    _error = other._error;
}

QDataStream &operator<<(QDataStream& stream, const RobotState& state)
{
    state.WriteTo(stream);
    return stream;
}

QDataStream &operator>>(QDataStream& stream, RobotState& state)
{
    state.ReadFrom(stream);
    return stream;
}
