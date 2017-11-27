#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;

Mat ela_algorithm(Mat img, int compression_value,int multiplier){
	/*setting up comprssion parameters to compress in jpeg*/
	vector<int> compressing_factor;
	compressing_factor.push_back(CV_IMWRITE_JPEG_QUALITY);
	compressing_factor.push_back(compression_value);

	imwrite("compressed.jpg",img,compressing_factor);
	Mat compressed_img=imread("compressed.jpg");

	/*spliting BGR image in components to calculate absolute difference between original and compressed image*/
	Mat bgr_img[3],diff[3];
	split(img,bgr_img);
	split(img,diff);
	Mat bgr_compressed[3];
	split(compressed_img,bgr_compressed); 

	absdiff(bgr_img[0], bgr_compressed[0], diff[0]);
	absdiff(bgr_img[1], bgr_compressed[1], diff[1]);
	absdiff(bgr_img[2], bgr_compressed[2], diff[2]);

	/*merging B,G,R components to get RGB(colored) image*/
	vector<Mat> merge_img;
    merge_img.push_back(diff[0]);
    merge_img.push_back(diff[1]);
    merge_img.push_back(diff[2]);
    Mat color;
    merge(merge_img, color);
    imwrite("diff.jpg",color);
    Mat diff_img=imread("diff.jpg");
   	
   	/*scaling-up the diffrence matrix obtained by multiplying with multiplier 
   	in order to see the minute changes more clearly*/
   	for (int row = 0; row < img.rows; ++row)
   	{
   		/*Values in image are unsinged char therefore declaring a pointer to acess and modify them*/
    	uchar* diff_ptr = diff_img.ptr<uchar>(row);
        for (int col = 0; col < img.cols; col++)
        {
			for (int channel = 0; channel < 3; channel++){
				/*if the value is greater than 255 after scaling up then make it equal to 255 else leave it*/
				if ((diff_ptr[channel] * multiplier)>=255){ 
					diff_ptr[channel] = 255; 
				}

				else{
					diff_ptr[channel] = diff_ptr[channel] * multiplier;
				}
			}
			/*increasing the pointer to get next value*/
            diff_ptr += 3;
        }
    }
    return diff_img;
}

int main(){
	int multiplier=30;
	int compression_value=95;
	Mat img;
	/*running ela on original image taken by mobile*/
	img=imread("original.jpg");
	Mat ela_result_img=ela_algorithm(img,compression_value, multiplier);
   	imwrite("result_original_img.jpg",ela_result_img);

   	/*running ela on photoshopped image which have a logo added in original image saved at 100% quality jpeg*/
   	Mat edited_img;
	edited_img=imread("photoshopped_img.jpg");
	Mat ela_result_edited_img=ela_algorithm(edited_img,compression_value, multiplier);
   	imwrite("result_edited_img.jpg",ela_result_edited_img);
}