#include "main_app.h"

main_app::main_app(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void main_app::addToGesturesToBeAdded(QListWidgetItem* item)
{
    item->setSelected(false);
    QIcon icon1(item->icon());
    QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(ui.toAddGesturesListWidget);
    __qlistwidgetitem1->setFlags(item->flags() & ~Qt::ItemIsSelectable);
    __qlistwidgetitem1->setIcon(icon1);
}

void main_app::removeFromGesturesToBeAdded(QListWidgetItem* item)
{
    delete item;
}