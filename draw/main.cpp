#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat src(600,700,CV_8UC3,Scalar(255,255,255));//创建一张800*800的背景
    Mat dst = src.clone();
    line (src, Point(100,50),Point(600,50),Scalar(59,131,189),3,LINE_8,0);
    circle (src, Point(300,300),100,Scalar(63,136,143),3,LINE_8,0);
    rectangle (src, Rect(100,150,500,50),Scalar(137,172,118),3,LINE_8,0);
    putText(src,string("RM"),Point(300,500),0,3,Scalar(150,153,146),8);
    namedWindow("draw",1);
    namedWindow("原图",1);
    imshow("draw",src);
    imshow("原图",dst);
    waitKey(0);
    return 0;
}