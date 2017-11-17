#pragma once
#include <QList>
enum class HandMovement {
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

class Gesture
{
public:
    Gesture();
    ~Gesture();
private:
    QList<HandMovement> gestures;
    Action action;
};

