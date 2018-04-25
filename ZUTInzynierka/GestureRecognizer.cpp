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
    pMOG2->setBackgroundRatio(0.25);
    pMOG2->setNMixtures(3);
    pMOG2->setShadowValue(0);
    pMOG2->setShadowThreshold(0.35);
}

void szybkafunkcja(std::vector<cv::Point> in, std::vector<int> hull, std::vector<cv::Point> &out)
{
    for(int i = 0; i < hull.size(); i++)
        out.push_back(in[hull[i]]);
}

GestureRecognizer::~GestureRecognizer()
{
}

int GestureRecognizer::algorithm(Mat frame)
{
    //imshow("Oryginalny obraz", frame);
    int fingers = 0;
    Mat mask;
    
    Mat element = getStructuringElement(0, { 5,5 });

    std::vector<std::vector<cv::Point>> contours;

    // FILTER FRAME ----------------------------------------

    GaussianBlur(frame, frame, { 7, 7 }, 0);
    //imshow("Po rozmyciu", frame);
    pMOG2->apply(frame, mask, learningRate);
    cv::Mat img_rgb(mask.size(), CV_8UC3);
    //imshow("Odejmowanie tla", mask);
    medianBlur(mask, mask, 7);
    //imshow("Rozmycie medianowe", mask);
    //Mat el = getStructuringElement(0, { 5,5 });
    /*filter2D(mask, mask, CV_8U, el);
    imshow("Filtr 2D", mask);
    cv::threshold(mask, mask, 195.0, 255, 0);
    imshow("Progowanie", mask);*/

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
    /*drawContours(mask, contours2, 0, { 255, 0 ,0 }, CV_FILLED);
    cv::cvtColor(mask, img_rgb, CV_GRAY2RGB);
    drawContours(img_rgb, contours2, 0, { 255, 0, 0 }, 4);
    imshow("Kontur", img_rgb);*/

    std::vector<std::vector<int>> hull(1);
    if (contours.size() && largest_area > (frame.rows * frame.cols) * 0.10)
    {
        convexHull(contours[largest_contour_index], hull[0]);
        int wide = 0;
        int count = 0;

        /*std::vector<std::vector<cv::Point>> con(1);
        szybkafunkcja(contours[largest_contour_index], hull[0], con[0]);
        drawContours(img_rgb, con, -1, { 0,255,0 }, 3);
        imshow("Otoczka wypukla", img_rgb);*/
        std::vector<cv::Vec4i> defects;
        convexityDefects(contours[largest_contour_index], hull[0], defects);

        for (const Vec4i& v : defects)
        {
            float depth = v[3] / 256.0;
            if (depth > 18) //  filter defects by depth, e.g more than 10
            {
                int startidx = v[0]; Point ptStart(contours[largest_contour_index][startidx]);
                int endidx = v[1]; Point ptEnd(contours[largest_contour_index][endidx]);
                int faridx = v[2]; Point ptFar(contours[largest_contour_index][faridx]);

                if (ptStart.y >= frame.rows - 50 || ptEnd.y >= frame.rows - 50)
                    continue;
                float angle = innerAngle(ptStart.x, ptStart.y, ptEnd.x, ptEnd.y, ptFar.x, ptFar.y);
                if (angle > 160)
                    continue;
                if (angle > 42.0)
                    ++wide;
                ++count;

                line(img_rgb, ptStart, ptEnd, Scalar(0, 198, 255), 2);
                line(img_rgb, ptStart, ptFar, Scalar(0, 198, 255), 2);
                line(img_rgb, ptEnd, ptFar, Scalar(0, 198, 255), 2);
                circle(img_rgb, ptFar, 4, Scalar(0, 198, 255), 4);
                
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
        //imshow("Wykrycie defektow", img_rgb);
        putText(frame, std::to_string(count), { 59, 59 }, CV_FONT_HERSHEY_PLAIN, 6.0, { 255, 210 ,70 }, 2);
        
        cv::waitKey(4);
    }
    if(show_window)
        imshow("Live", mask);
    return fingers;
}

void GestureRecognizer::set_show_hand(bool flag)
{
    show_window = flag;
}
