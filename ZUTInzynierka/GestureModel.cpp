#include "GestureModel.h"



GestureModel::GestureModel()
{
}


GestureModel::~GestureModel()
{
}

int GestureModel::rowCount(const QModelIndex & parent) const
{
    return list.count();
}
