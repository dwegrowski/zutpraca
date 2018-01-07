#include "Gesture.h"
#include "qstring.h"
#include "qmap.h"



Gesture::Gesture()
{
}

Gesture::~Gesture()
{
}

QMap<Action, QString> action_command{ {Action::MUTE, "nircmd.exe mutesysvolume 1" } };