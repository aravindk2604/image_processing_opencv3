/*
*	Image loading and extraction of details from the 
*	image. Display the image in a window same as the 
*	image size
*
*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>

int main(int argc, char** argv) {

	// check for appropriate command 
	if(argc != 2){
		std::cout << "Usage: display_image ImageToLoadAndDisplay\n";
		return -1;
	}

	// Load an image from a directory. 
	cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	// check for invalid image
	if(!img.data) {
		std::cout << "Could not find/load the image\n";
		return -1;
	}

	// print out some info about the image.
	int rows = img.rows;
	int cols = img.cols;
	int channel = img.channels();

	std::cout << "The image details are: \n";
	std::cout << "Rows: " << rows << " Cols: " << cols << " Channels: " << channel << "\n";

	// display the image in a window
	cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display Window", img);

	cv::waitKey(0);
	return 0;
}