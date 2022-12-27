#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat src;
    src = imread ("7-2.jpg");
    if (src.empty()) 
    {
      cout <<"Failed to open the pictre." << endl;
     return -1;
    }
    namedWindow("原图",1);
    imshow("原图",src);
    cvtColor (src,src,COLOR_RGB2GRAY); //转换为灰度图
    Mat dst = src.clone();
    int height = src.rows;
    int width = src.cols;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int gray =src.at<uchar>(i,j);
            dst.at<uchar>(i,j) = pow(gray,0.5);//灰度值开方
        }
    }
    normalize (dst,dst,0,255,NORM_MINMAX);//归一化，将灰度值归一到0-255之间
    imshow("gamma矫正效果图",dst);
    waitKey(0);
    return 0;
}
