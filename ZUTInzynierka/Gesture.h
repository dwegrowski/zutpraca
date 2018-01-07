#pragma once
#include <QList>
#include <qvector.h>

enum class HandMovement {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum class Action {
    NOTHING,
    SHUTDOWN,
    RESTART,
    VOLUME_UP,
    VOLUME_DOWN,
    MUTE,
    LOCK,
    LOGOUT
};

extern QMap<Action, QString> action_command;

class Gesture
{
public:
    Gesture();
    ~Gesture();

    QVector<HandMovement> gestures;
    Action action;
};

