#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    Mat src,dst,img;
    src = imread("终极考察1.jpg");
    img = src.clone();
    imshow("原图",src);
    cvtColor(src,dst,COLOR_RGB2GRAY);
    vector<Vec3f> circles;
    HoughCircles(dst,circles,HOUGH_GRADIENT,1,10,100,30,1,100);//霍夫圆检测
    for(int i=0;i<circles.size();i++){
        Vec3f c = circles[i];
        circle(src,Point(c[0],c[1]),c[2],Scalar(0,255,255),-1);
    }
    Mat labels;
    labels.create(src.size(),src.type());
    for (int i=0;i<src.rows;i++){
        for(int j=0;j<src.cols;j++){
            if(src.at<Vec3b>(i,j)!=Vec3b(0,255,255))
                img.at<Vec3b>(i,j)=Vec3b(0,0,0);
        }
    }
    threshold(img,img,5,255,THRESH_TOZERO);
    imshow("效果图",src);
    imshow("ROI",img);
    waitKey(0);
    return 0;
}