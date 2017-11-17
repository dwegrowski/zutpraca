#pragma once
#include <QAbstractListModel>
#include "Gesture.h"

class GestureModel : QAbstractItemModel
{
    Q_OBJECT
public:
    GestureModel();
    ~GestureModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    QList<Gesture> list;
};

