#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
    //读取图像
    Mat srcImage = imread("1.jpg");
    //显示原图
    imshow("原图",srcImage);
    //参数定义
    Mat dstImage,edge,grayImage;
    //创建与src同类型和大小的矩阵(dst)
    dstImage.create(srcImage.size(),srcImage.type());
    //将原图转换为灰度图像
    cvtColor(srcImage,grayImage,COLOR_BGR2GRAY);
    //使用3*3内核降噪
    blur(grayImage,edge,Size(3,3));
    //运行canny算子
    Canny(edge,edge,3,9,3);
    //显示效果图
    imshow("canny边缘检测效果图",edge);
    waitKey(0);

    return 0;
}
