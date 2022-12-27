#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(void)
{
    //读取图像
    Mat srcImage=imread("1.jpg");
    //显示原图
    imshow("原图",srcImage);
    //进行均值滤波操作
    Mat dstImage;
    blur(srcImage,dstImage,Size(7,7));
    //显示效果图
    imshow("均值滤波效果图",dstImage);
    waitKey(0);
    return 0;
}