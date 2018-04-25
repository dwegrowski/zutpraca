#pragma once
#include <QAbstractListModel>
#include "Gesture.h"

const QString filename = "user_gestures.txt";

class GestureModel
{
public:
    GestureModel();
    ~GestureModel();

    void add(Gesture);
    void saveToFile(Gesture);
    QList<Gesture> readFromFile();
    void removeFromFile(int row);
    QVector<Gesture> list;
};

