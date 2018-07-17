#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>

int main(int argc, char** argv) {

    // check if the command is correct
    if(argc != 2) {
        std::cout << "Usage: display_image ImageToLoadAndDisplay\n";
        return -1;
    }
    
    // Load an image
    cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

    if(!img.data) {
        std::cout << "Unable to load/find image\n";
        return -1;
    }


    // for color image without alpha
    if(img.channels() == 3) {
        for(auto i =0; i < img.rows; ++i) {
            // a pointer to the pixel array
            uchar *p = img.ptr<uchar>(i);
            for(auto j=0; j < img.cols; ++j) {
                p[j*img.channels() + 0] = p[j*img.channels() + 0]; // blue
                p[j*img.channels() + 1] = 0; // green
                p[j*img.channels() + 2] = 0; // red
            }
        }
    }

    if(img.channels() == 1) {
        for(int i=0; i<img.rows; ++i) {
            uchar* p = img.ptr<uchar>(i);
            for(int j=0; j<img.cols; ++j) {
                if(p[j] < 100) p[j] = 0;
                else if (p[j] > 155) p[j] = 255;
                else p[j] = p[j];
            }
        }
    }

    cv::namedWindow("display image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Image window", img);
    cv::imwrite("modifiedImage.jpg", img);
    cv::waitKey(0);
    return 0;
}