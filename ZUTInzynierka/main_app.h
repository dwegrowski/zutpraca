#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_app.h"
#include "Gesture.h"
#include "GestureModel.h"
#include "VideoThread.h"
#include "qsystemtrayicon.h"

class main_app : public QMainWindow
{
    Q_OBJECT

public:
    main_app(QWidget *parent = Q_NULLPTR);

private:
    VideoThread vid;
    Ui::main_appClass ui;
    QMap<QString, Action> enumMap_action;
    QMap<QString, HandMovement> enumMap_hand;
    GestureModel data;
    void addGesture(Gesture g);
    void createGestureWidget(Gesture &g);
public slots:
    void actionStart();
    void actionStop();
    void actionInfo();
    void addToGesturesToBeAdded();
    void removeFromGesturesToBeAdded(QListWidgetItem* item);
    void addGesture();
    
    void removeFromGestures(QListWidgetItem* item);
};
