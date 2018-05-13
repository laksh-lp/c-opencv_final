#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i=0;
    char image[1000];
    cvNamedWindow("mainWin");
    CvCapture* capture = cvCreateFileCapture( argv[1]);
    if(argv[1]==NULL){
        printf("Cannot laod video\n");
        return 0;
    }

    IplImage* frame,*output;
    struct tm *local;
    time_t t;
    printf("Press 's' to save image 'Esc' to exit\n");
    while (1)
    {
        frame = cvQueryFrame( capture );
        if ( !frame ) break;
        cvShowImage( "mainWin", frame );
        char c = cvWaitKey(33);
        if (c=='s')
        {
            t = time(NULL);
            local = localtime(&t);
            output=cvCreateImage(cvGetSize(frame),8,3);
            sprintf(image,"%s.jpg",asctime(local));
            cvSaveImage(image,frame);
            cvCopy(frame,output);
            cvNamedWindow("Result");
            cvShowImage("Result",output);
            cvReleaseImage(&output);
            i++;
        }
        if ( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "mainWin" );
    return 0;
} 