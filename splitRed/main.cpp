#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat src,dst;
    src = imread ("8.png");
    imshow("原图",src);
    dst.create(src.size(),src.type());
    cvtColor (src,dst,COLOR_BGR2HSV);
    inRange (dst,Scalar(0,10,10),Scalar(10,255,255),dst);
    imshow("提取红色素效果图",dst);
    waitKey(0);
    return 0;
}