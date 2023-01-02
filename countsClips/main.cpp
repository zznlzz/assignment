#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
    Mat src, dst;
    src = imread("11.png");
    if(src.empty()) cout << "Failed to open the picture." << endl;
    cvtColor(src, dst, COLOR_BGR2GRAY);
    threshold(dst,dst,100,255,THRESH_BINARY_INV);
    Mat element = getStructuringElement(MORPH_ELLIPSE, Point(5,5));
    morphologyEx(dst,dst,MORPH_OPEN,element);//开运算去小白点
    imshow("1",dst);
    Mat labels, stats, centroids;
    int n,m=0;
    n = connectedComponentsWithStats(dst, labels, stats, centroids);
    for (int i=1; i<n; i++){
        int s = stats.at<int>(i, CC_STAT_AREA);
        if (s>5000) m++;//面积到达一定值才计数
    }
    cout << m << endl;
    waitKey(0);
    return 0;
}