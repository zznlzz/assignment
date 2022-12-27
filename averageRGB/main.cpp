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
			dst.at<Vec3b>(row,col)[0] = (b+g+r)/3;
			dst.at<Vec3b>(row,col)[1] = (b+g+r)/3;
			dst.at<Vec3b>(row,col)[2] = (b+g+r)/3;
		}
	}
	namedWindow("3通道取平均效果图",WINDOW_AUTOSIZE);
	imshow("3通道取平均效果图",dst);
	waitKey(0);
	return 0;
}
