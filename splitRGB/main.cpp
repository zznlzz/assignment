#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char** argv) 
{
	Mat src,dst;
	vector<Mat> channel;
	src = imread("8.png");
	namedWindow("原图",WINDOW_AUTOSIZE);
	imshow("原图",src);
	split(src,channel);
	imshow("蓝通道",channel.at(0));
	imshow("绿通道",channel.at(1));
	imshow("红通道",channel.at(2));
	waitKey(0);
	return 0;
}
