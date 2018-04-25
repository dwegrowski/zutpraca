#pragma once
#include "Gesture.h"
#include "opencv2\videoio.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\video\background_segm.hpp"
#include "opencv2\imgproc.hpp"

using namespace cv;

class GestureRecognizer
{
    const float DEFAULT_LEARNING_RATE = 0.0005;
    const float REMOVE_NOISE_LEARNING_RATE = 0.01;
    Ptr<BackgroundSubtractorMOG2> pMOG2;
    
    float learningRate = DEFAULT_LEARNING_RATE;
    bool show_window = false;

    float innerAngle(float px1, float py1, float px2, float py2, float cx1, float cy1);
public:
    GestureRecognizer();
    ~GestureRecognizer();
    int algorithm(Mat frame);
    void set_show_hand(bool);
};

