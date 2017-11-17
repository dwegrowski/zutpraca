#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_app.h"

class main_app : public QMainWindow
{
    Q_OBJECT

public:
    main_app(QWidget *parent = Q_NULLPTR);

private:
    Ui::main_appClass ui;

public slots:
    void addToGesturesToBeAdded(QListWidgetItem* item);
    void removeFromGesturesToBeAdded(QListWidgetItem* item);
};
