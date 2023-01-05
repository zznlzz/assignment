#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    Mat src,dst,img;
    src = imread("终极考察2.jpg");
    imshow("原图",src);
    img = src.clone();
    cvtColor(src, dst, COLOR_BGR2GRAY);
    threshold(dst,dst,165,255,THRESH_BINARY);
    Mat labels, stats, centroids;
    int n = connectedComponentsWithStats(dst,labels,stats,centroids);
    for(int i=1;i<n;i++){
        if(stats.at<int>(i,CC_STAT_AREA)>700){
            int x = stats.at<int>(i,CC_STAT_LEFT);
            int y = stats.at<int>(i,CC_STAT_TOP);
            int width = stats.at<int>(i,CC_STAT_WIDTH);
            int height = stats.at<int>(i,CC_STAT_HEIGHT);
            Mat dstROI = dst(Rect(x,y,width,height));//感兴趣区域
            Mat imgROI = img(Rect(x,y,width,height));
            Mat element = getStructuringElement(MORPH_ELLIPSE, Point(5,5));
            morphologyEx (dstROI, dstROI, MORPH_OPEN, element);//开运算
            morphologyEx (dstROI, dstROI, MORPH_CLOSE, element);//闭运算
            //morphologyEx (dstROI, dstROI, MORPH_OPEN, element);//开运算
            //morphologyEx (dstROI, dstROI, MORPH_CLOSE, element);//闭运算
            Canny(dst, dst, 90,180,3); //边缘检测
            Mat label, stat, centroid;
            int m = connectedComponentsWithStats(dstROI,label,stat,centroid);
            for(int j=1;j<m;j++){
                if(stat.at<int>(j,CC_STAT_AREA)>300){
                    for(int row = 0; row < dstROI.rows; row++){
		                for(int col = 0; col < dstROI.cols; col++){
                            if(label.at<int>(row,col)==j)
                                imgROI.at<Vec3b>(row,col) = Vec3b(0,255,255);//黄色边缘
		                }
	                }
                }
            }
            rectangle (img, Rect(x,y,width,height), Scalar(0,0,255), 3, LINE_8, 0);//红框
        }
    }
    Canny(dst, dst, 90,180,3); 
    imshow("效果图",img);
    waitKey(0);
    return 0;
}