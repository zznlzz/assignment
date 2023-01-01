#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("9.png"),dst1,dst2,dst3,dst4;
	imshow("原图",src);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Point(15,15));
	erode(src,dst1,element);//腐蚀
	imshow("腐蚀效果图",dst1);
	dilate(src,dst2,element);//膨胀
	imshow("膨胀效果图",dst2);
	morphologyEx (src, dst3, MORPH_OPEN, element);//开运算
	imshow("开运算效果图",dst3);
	morphologyEx (src, dst4, MORPH_CLOSE, element);//闭运算
	imshow("闭运算效果图",dst4);
	waitKey(0);
	return 0;
}
