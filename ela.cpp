#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;

int main(){
	Mat img,compressed_img,compressed_img_resized;
	img=imread("original.jpg");

	//compresing image by certain factor ie: lossy compression
	vector<int> compressing_factor;
	compressing_factor.push_back(CV_IMWRITE_JPEG_QUALITY);
	compressing_factor.push_back(90);

	imwrite("compressed.jpg",img);
	compressed_img=imread("compressed.jpg");
	//resize image since the image was of higher resolution
	resize(compressed_img, compressed_img_resized, Size(),0.30,0.30);
	imshow("compressed image",compressed_img_resized);
	waitKey(0);
}