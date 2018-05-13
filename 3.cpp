#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	int frame_count = 0;
	int ch=0;

	while (true)
    {
        
        Mat frame;
        cap.read(frame);
        ch >> waitKey(25);
        if(ch == 32)
        {
            // i=i+1;
            // string nm = (i);
            // imwrite("/home/laksh/Desktop/ books/nm.jpg", frame);
            char filename[128];
            sprintf(filename, "frame_%06d.jpg", frame_count);
            imwrite(filename, frame);
            frame_count++;
        }   

 
        if(ch == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
        imshow("Display", frame);
    }





	return 0;
}