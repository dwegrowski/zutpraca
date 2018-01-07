#include "Gesture.h"
#include "qstring.h"
#include "qmap.h"



Gesture::Gesture()
{
}

Gesture::~Gesture()
{
}

QMap<Action, QString> action_command{ {Action::MUTE, "nircmd.exe mutesysvolume 2" },
                                      {Action::LOCK, "rundll32.exe user32.dll,LockWorkStation"},
                                      {Action::LOGOUT, "shutdown -l"},
                                      {Action::RESTART, "shutdown -r"},
                                      {Action::SHUTDOWN, "shutdown -s"},
                                      {Action::VOLUME_DOWN, "nircmd.exe changesysvolume 5"},
                                      {Action::VOLUME_UP, "nircmd.exe changesysvolume -5"} };