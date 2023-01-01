#include <opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace cv;

int main (int argc, char** argv)
{
    Mat src,dst,img;
    src = imread("10.png");
    if (src.empty()) cout << "Failed to open the picture." << endl;
    threshold (src,dst,84,255,THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_ELLIPSE, Point(5,5));
    morphologyEx(dst,dst,MORPH_OPEN,element);//开运算去小白点
    //imshow("二值化效果图",dst);
    cvtColor(dst,dst,COLOR_RGB2GRAY);
    Mat labels, stats, centroids;
    int n;
    n = connectedComponentsWithStats(dst, labels, stats, centroids);
    cout << n << endl;
    img.create(src.size(),src.type());
    int height = src.rows;
	int width = src.cols;
    srand(time(0));
    vector<Vec3b> colors(n);
    colors[0] = Vec3b(0, 0, 0); //不改变背景色（label=0）
    for (int i = 1; i < n; i++) {//随机各个连通域颜色
        colors[i] = Vec3b(rand() % 256, rand() % 256, rand() % 256);
    }
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			int label = labels.at<int>(row,col);
            img.at<Vec3b>(row,col) = colors[label];
		}
	}
    for (int i=1; i<=n; i++){
        int x = stats.at<int>(i,CC_STAT_LEFT);
        int y = stats.at<int>(i,CC_STAT_TOP);
        int width = stats.at<int>(i,CC_STAT_WIDTH);
        int height = stats.at<int>(i,CC_STAT_HEIGHT);
        rectangle (img, Rect(x,y,width,height), Scalar(255,255,255), 1, LINE_8, 0);
    }
    imshow("Bounding Box",img);
    waitKey(0);
    return 0;
}
