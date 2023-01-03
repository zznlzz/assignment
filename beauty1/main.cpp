#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv) 
{
    Mat src, dst1, dst2,img;
    src = imread("1.jpg");
    imshow("原图",src);
    if (src.empty()) cout << "Failed to open the picture." << endl;
    cvtColor(src, dst1, COLOR_RGB2GRAY);
    threshold (dst1,dst1,142,255,THRESH_BINARY_INV);//特别黑的小点
    cvtColor(src, dst2, COLOR_RGB2GRAY);
    threshold (dst2,dst2,163,255,THRESH_BINARY);//特别白的小点
    //imshow("1",dst2);
    Mat labels1, labels2,stats1, stats2, centroids;
    int n1,n2;
    n1 = connectedComponentsWithStats(dst1, labels1, stats1, centroids);
    n2 = connectedComponentsWithStats(dst2, labels2, stats2, centroids);
    img.create(src.size(),src.type());
    int s1[n1],s2[n2];
    for(int i=0;i<n1;i++){
        s1[i] = stats1.at<int>(i, CC_STAT_AREA);
    }
    for(int i=0;i<n2;i++){
        s2[i] = stats2.at<int>(i, CC_STAT_AREA);
    }
    int height = src.rows;
	int width = src.cols;
    for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			int label1 = labels1.at<int>(row,col);
            int label2 = labels2.at<int>(row,col);
            if ((s1[label1]<50||s2[label2]<35)&&(row>=330&&row<=530&&col>=100))
                img.at<Vec3b>(row,col) = Vec3b(255,255,255);
            else
                img.at<Vec3b>(row,col) = Vec3b(0,0,0);
		}
	}
    cvtColor(img, img, COLOR_RGB2GRAY);
    threshold(img,img,245,255,THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_ERODE,Size(6.5,6.5));
    dilate(img,img,element);
    imshow("2",img);
    inpaint(src, img, src,5,INPAINT_NS);
    imshow("效果图",src);
    waitKey(0);
    return 0;
}
