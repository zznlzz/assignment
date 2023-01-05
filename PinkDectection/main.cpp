#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat src,dst,dst1,dst2,img;
    src = imread("终极考察3.jpg");
    img = src.clone();
    imshow("原图",src); 
    dst.create(src.size(),src.type());
    dst1.create(src.size(),src.type());
    dst2.create(src.size(),src.type());
    cvtColor (src,dst,COLOR_BGR2HSV);
    inRange (dst,Scalar(160,20,20),Scalar(180,250,250),dst1);
    inRange (dst,Scalar(0,20,20),Scalar(8,250,250),dst2);
    addWeighted(dst1,0.5,dst2,0.5,0,dst);
    Mat element = getStructuringElement(MORPH_ELLIPSE, Point(15,15));
    morphologyEx (dst, dst, MORPH_OPEN, element);//开运算
    //morphologyEx (dst, dst, MORPH_CLOSE, element);//闭运算
    //imshow("提取红色素效果图",dst);
    //cvtColor(dst,dst,COLOR_RGB2GRAY);
    Mat labels, stats, centroids;
    int n = connectedComponentsWithStats(dst,labels,stats,centroids);    
    for(int i=1;i<n;i++){
        if(stats.at<int>(i,CC_STAT_AREA)>700){
            int x = stats.at<int>(i,CC_STAT_LEFT);
            int y = stats.at<int>(i,CC_STAT_TOP);
            int width = stats.at<int>(i,CC_STAT_WIDTH);
            int height = stats.at<int>(i,CC_STAT_HEIGHT);
            rectangle (img, Rect(x,y,width,height), Scalar(50,150,80), 2, LINE_8, 0);//红框
        }
    }
    imshow("效果图",img);
    waitKey(0);
    return 0;
}