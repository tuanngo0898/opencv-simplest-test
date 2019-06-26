#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap; // open the default camera
    cap.open(0);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH); 
    int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    
    VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height));
    
    Mat frame;
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        video.write(frame);
        imshow("frame", frame);
        if(waitKey(30) >= 0) break;
    }

    cap.release();
    video.release();
    return 0;
}