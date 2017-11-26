#include <opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(){
	Mat img,resaved_img;
	img=imread("original.jpg");
	imwrite("resaved.jpg",img);
	resaved_img=imread("resaved.jpg");
	imshow("resaved image",resaved_img);
	waitKey(0);
}