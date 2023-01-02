#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
    Mat src,dst1,dst2,dst3;
    VideoCapture cap;//声明相机捕获对象
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
    cap.set(CAP_PROP_FRAME_WIDTH,480);//图像的宽
    cap.set(CAP_PROP_FRAME_HEIGHT,480);//图像的高
    cap.open(0);
    if(!cap.isOpened()) {
        cout << "Failed to open camera." << endl;
        return -1;
    }
     
    while (true)
    {
        cap >> src;  
        imshow("原图",src);
        if (waitKey(10) >= 0) break;
    }
    cap.release();
    destroyAllWindows();
    blur(src,dst1,Size(7,7));//均值滤波
    imshow("均值滤波效果图",dst1);
    GaussianBlur(src,dst2,Size(7,7),0,0);//高斯滤波
    imshow("高斯滤波效果图",dst2);
    medianBlur(src,dst3,7);//中值滤波
    imshow("中值滤波效果图",dst3);
    waitKey(0);
    return 0;
}