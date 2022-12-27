#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char** argv) 
{
	Mat src,dst;
	src = imread("8.png");
	namedWindow("原图",WINDOW_AUTOSIZE);
	imshow("原图",src);
	dst.create(src.size(), src.type());
	int height = src.rows;
	int width = src.cols;
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			int b = src.at<Vec3b>(row,col)[0];
			int g = src.at<Vec3b>(row,col)[1];
			int r = src.at<Vec3b>(row,col)[2];
			uchar threshold = 100;
			int average = (b+g+r)/3;
			if (average>threshold) average = 255;
			else average = 0;
			dst.at<Vec3b>(row,col)[0] = average;
			dst.at<Vec3b>(row,col)[1] = average;
			dst.at<Vec3b>(row,col)[2] = average;
		}
	}
	namedWindow("二分法效果图",WINDOW_AUTOSIZE);
	imshow("二分法效果图",dst);
	waitKey(0);
	return 0;
}
