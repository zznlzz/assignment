#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	//载入图像
	Mat srcImage = imread("1.jpg");
	//显示原图
	imshow("原图",srcImage);
	//腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
	Mat dstImage;
	erode(srcImage,dstImage,element);
	//显示效果图
	imshow("腐蚀效果图",dstImage);
	waitKey(0);

	return 0;
}
