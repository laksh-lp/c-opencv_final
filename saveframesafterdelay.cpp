#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main (int argc, char **argv)
{
	VideoCapture cap(0);

	int frame_count = 0;
  int i = 0;
	while(1)
  {

     Mat frame;
     cap.read(frame);
     if( frame.empty()) break;
     imshow("video", frame);
     char filename[80];
     sprintf(filename,"/home/laksh/Desktop/ books_%d.png",i);
     imwrite(filename, frame);
     i++;
     char key = waitKey(10);
     if ( key == 27) break;
    
  }

  return 0;
}