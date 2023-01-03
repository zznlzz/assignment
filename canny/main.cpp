#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv)
{
    Mat src,dst;
    src = imread("1.jpg");
    imshow("原图",src);
    Mat edge,gray;
    //创建与src同类型和大小的矩阵(dst)
    dst.create(src.size(),src.type());
    //将原图转换为灰度图像
    cvtColor(src,gray,COLOR_BGR2GRAY);
    //使用3*3内核降噪
    blur(gray,edge,Size(3,3));
    //运行canny算子
    Canny(edge,edge,3,9,3);
    imshow("canny边缘检测效果图",edge);
    waitKey(0);
    return 0;
}
