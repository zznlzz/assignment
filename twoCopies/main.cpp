#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
    Mat srcMat,deepMat,shallowMat;
    srcMat = imread("8.png");
    namedWindow("原图",WINDOW_NORMAL);
	imshow("原图",srcMat);
    shallowMat = srcMat;//浅拷贝
    deepMat = srcMat.clone();//深拷贝
	//srcMat.create(srcMat.size(), srcMat.type());
    int height = srcMat.rows;
	int width = srcMat.cols;
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			int b = srcMat.at<Vec3b>(row,col)[0];
			int g = srcMat.at<Vec3b>(row,col)[1];
			int r = srcMat.at<Vec3b>(row,col)[2];
			uchar threshold = 100;
			int average = (b+g+r)/3;
			if (average>threshold) {average = 255;}
			else {average = 0;}
			srcMat.at<Vec3b>(row,col)[0] = average;
			srcMat.at<Vec3b>(row,col)[1] = average;
			srcMat.at<Vec3b>(row,col)[2] = average;
		}
	}
	imshow("浅拷贝变换后效果图",shallowMat);
	imshow("深拷贝变换后效果图",deepMat);
    waitKey(0);
	return 0;
}