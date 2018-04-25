#include "VideoThread.h"
#include "GestureRecognizer.h"
#include <iostream>
#include <QElapsedTimer>
#include <qdebug.h>
#include <chrono>

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

void VideoThread::set_show_window(bool flag)
{
    if (!flag)
        destroyWindow("Live");
    recognizer.set_show_hand(flag);
}

void VideoThread::run()
{
    double sr = 0;
    double l = 0;
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
        //auto start = std::chrono::steady_clock::now();
        int hand2 = recognizer.algorithm(frame);
        //auto end = std::chrono::steady_clock::now();
        //auto diff = end - start;
        //l = l + 1.0;
        //sr = ((sr * l) + std::chrono::duration <double, std::milli>(diff).count()) / l;
        //qDebug() << "srednia - " << sr << endl;
        //qDebug() << std::chrono::duration <double, std::milli>(diff).count() << " ns" << endl;
        if (hand2 != hand)
        {
            auto t = timer.restart();
            qDebug() << hand2 << hand << t;
            if (t >= 500)
            {
                if (hand != 0)
                {
                    qDebug() << "APPENDUJE " << hand;
                    g.append(static_cast<HandMovement>(hand));
                }              
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
