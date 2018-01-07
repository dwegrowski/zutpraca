#include "GestureRecognizer.h"
#include <math.h>
#include <opencv2\core\cvdef.h>

using namespace cv;

float GestureRecognizer::innerAngle(float px1, float py1, float px2, float py2, float cx1, float cy1)
{
    float vec1x = px1 - cx1;
    float vec1y = py1 - cy1;
    float vec2x = px2 - cx1;
    float vec2y = py2 - cy1;

    float dist1 = sqrt(vec1x*vec1x + vec1y*vec1y);
    float dist2 = sqrt(vec2x*vec2x + vec2y*vec2y);

    float iloczyn_skalarny = vec1x * vec2x + vec1y * vec2y;

    float wynik = acos(iloczyn_skalarny / (dist1*dist2));
    return wynik * 180.0 / CV_PI;
}

GestureRecognizer::GestureRecognizer()
{
    pMOG2 = createBackgroundSubtractorMOG2();
}


GestureRecognizer::~GestureRecognizer()
{
}

int GestureRecognizer::algorithm(Mat frame)
{
    int fingers = 0;
    Mat mask;
    
    Mat element = getStructuringElement(0, { 5,5 });

    std::vector<std::vector<cv::Point>> contours;

    // FILTER FRAME ----------------------------------------

    GaussianBlur(frame, frame, { 7, 7 }, 0);
    pMOG2->apply(frame, mask, 0);
    medianBlur(mask, mask, 7);
    Mat el = getStructuringElement(0, { 5,5 });
    filter2D(mask, mask, CV_8U, el);
    cv::threshold(mask, mask, 195.0, 255, 0);

    // FIND CONTOURS -------------------------------------------------

    findContours(mask, contours, CV_RETR_LIST, CHAIN_APPROX_SIMPLE);
    if (contours.size() == 0)
        return fingers;

    // FIND THE BIGGEST AREA THAT IS SUPPOSED TO BE A HAND

    int largest_contour_index = 0;
    double largest_area = 0;
    for (int i = 0; i< contours.size(); i++)        // iterate through each contour. 
    {
        double a = contourArea(contours[i]);        //  Find the area of contour
        if (a > largest_area) {
            largest_area = a;
            largest_contour_index = i;              //Store the index of largest contour
        }
    }

    // FILL THE POSSIBLE HAND REGION
    std::vector<std::vector<cv::Point>> contours2{ contours[largest_contour_index] };
    drawContours(mask, contours2, 0, { 255, 0 ,0 }, CV_FILLED);

    std::vector<std::vector<int>> hull(1);
    if (contours.size() && largest_area > (frame.rows * frame.cols) * 0.075)
    {
        convexHull(contours[largest_contour_index], hull[0]);
        int wide = 0;
        int count = 0;

        //drawContours(frame, hull[0], -1, { 0,255,0 }, 3);
        std::vector<cv::Vec4i> defects;
        convexityDefects(contours[largest_contour_index], hull[0], defects);
        int size = 2;
        for (const Vec4i& v : defects)
        {
            float depth = v[3] / 256.0;
            if (depth > 18) //  filter defects by depth, e.g more than 10
            {
                Rect middle{ 50, 50, frame.cols - 100, frame.rows - 100 };
                int startidx = v[0]; Point ptStart(contours[largest_contour_index][startidx]);
                int endidx = v[1]; Point ptEnd(contours[largest_contour_index][endidx]);
                int faridx = v[2]; Point ptFar(contours[largest_contour_index][faridx]);

                if (ptStart.y >= frame.rows - 50 || ptEnd.y >= frame.rows - 50)
                    continue;
                float angle = innerAngle(ptStart.x, ptStart.y, ptEnd.x, ptEnd.y, ptFar.x, ptFar.y);
                if (angle > 42.0)
                    ++wide;
                ++count;

                line(frame, ptStart, ptEnd, Scalar(255, 255, 0), 3);
                line(frame, ptStart, ptFar, Scalar(0, 255, 0), 2);
                line(frame, ptEnd, ptFar, Scalar(0, 0, 255), 1);
                circle(frame, ptFar, 4, Scalar(0, 255, 0), size++);
                
            }
        }
        if (count == 3)
        {
            if (wide == 2)
                count = 3;
            else
                count = 4;
        }
        else if (count == 4)
            count = 5;
        fingers = count;
        putText(frame, std::to_string(count), { 59, 59 }, CV_FONT_HERSHEY_PLAIN, 6.0, { 255, 210 ,70 }, 2);
        imshow("Live", mask);
        imshow("Live2", frame);
        cv::waitKey(4);
    }
    return fingers;
}
