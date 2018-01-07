#pragma once

#include <QThread>
#include "GestureModel.h"
#include "GestureRecognizer.h"
#include "qsystemtrayicon.h"

class VideoThread : public QThread
{
    Q_OBJECT

public:
    VideoThread(GestureModel* model, QObject *parent = 0);
    ~VideoThread();

protected:
    void run() override;

private:
    GestureModel *model;
    GestureRecognizer recognizer;
    QSystemTrayIcon *tray;
    void process(QVector<HandMovement>);
};
