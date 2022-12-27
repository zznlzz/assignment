#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    //打开摄像头

    VideoCapture cap;//声明相机捕获对象
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
    cap.set(CAP_PROP_FRAME_WIDTH,640);//图像的宽
    cap.set(CAP_PROP_FRAME_HEIGHT,480);//图像的高

    int deviceID = 0;//相机设备号
    cap.open(deviceID);
    if (!cap.isOpened())
    {
        cerr << "Error: unable to open camera." << endl;
        return -1;
    }else{
        cout <<"Successfully turned on the camera."<< endl;
    }

    //计算帧率

    int num_frames = 120;
    time_t start,end;
    Mat frame;
    time(&start);//计时开始
    for (int i=0; i<num_frames;i++){//数完num_frames帧
        cap >> frame;
    }
    time(&end);//计时结束
    double fps,seconds = difftime (end,start);//计时
    fps = num_frames / seconds;
    cout << "Camera FPS is " << fps << endl;

    //输出图片

    Mat img;
    while (true)
    {
        cap >> img;
        namedWindow("camera",1);
        if (img.empty() == false)
        {
            imshow("camera",img);
            cout << "Successfully output pictures." << endl;
        }else{
            cerr<<"Error: unable to read imagine." << endl;
        }
        
       if (waitKey(10) >= 0) break;
    }
    cap.release();
    destroyAllWindows();

    return 0;
}