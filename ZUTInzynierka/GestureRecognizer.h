#pragma once
#include "Gesture.h"
#include "opencv2\videoio.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\video\background_segm.hpp"
#include "opencv2\imgproc.hpp"

using namespace cv;

class GestureRecognizer
{
    Ptr<BackgroundSubtractorMOG2> pMOG2;

    float innerAngle(float px1, float py1, float px2, float py2, float cx1, float cy1);
public:
    GestureRecognizer();
    ~GestureRecognizer();
    int algorithm(Mat frame);
};

