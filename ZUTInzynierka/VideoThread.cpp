#include "VideoThread.h"
#include "GestureRecognizer.h"
#include <iostream>
#include <QElapsedTimer>
#include <qdebug.h>

VideoThread::VideoThread(GestureModel* model, QObject *parent)
    : QThread(parent)
{
    this->model = model;
    tray = new QSystemTrayIcon(QIcon(":/main_app/trayIcon"));
    tray->show();
}

VideoThread::~VideoThread()
{
}

void VideoThread::run()
{
    QVector<HandMovement> g;
    bool start_symbol = false;
    
    int hand = 0;
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        return;
    }
    QElapsedTimer timer;
    timer.start();
    for(;;)
    {
        cv::Mat frame;
        cap.read(frame);

        if (frame.empty()) {
            break;
        }
        int hand2 = recognizer.algorithm(frame);

        if (hand2 != hand)
        {
            //tray->showMessage(QString("Recognized gesture"), QString::number(hand2), QSystemTrayIcon::Information, 800);
            
            auto t = timer.restart();
            qDebug() << hand2 << hand << t;
            if (t >= 900)
            {
               /* qDebug() << "Wczytano " << hand;
                if (hand == 0)
                {
                    if (g.size() != 0)
                    {
                        process(g);
                        g.clear();
                        continue;
                    }
                    
                }
                else
                {*/
                if (hand2 != 0)
                {
                    qDebug() << "APPENDUJE " << hand2;
                    g.append(static_cast<HandMovement>(hand2));
                }
                //}
                
            }
            hand = hand2;
        }
        else
        {
            if (hand == 0 && timer.hasExpired(800) && g.size() != 0)
            {
                process(g);
                g.clear();
            }
        }
    }
}

void VideoThread::process(QVector<HandMovement> g)
{
    for (int i = 0; i < model->list.size(); i++)
    {
        if (model->list[i].gestures == g) //found gesture
        {
            Action a = model->list[i].action;
            system(qPrintable(action_command[a]));
        }
    }
}
