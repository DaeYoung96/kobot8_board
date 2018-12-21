#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

void main()
{
	//file load
	VideoCapture capture(0);
	Mat frame;

	//check
	if (!capture.isOpened()) {
		cout << "AVI file can not open" << endl;
		return ;
	}

	//create windows
	namedWindow("w");

	while (1) {
		//grab frame from file & throw to Mat
		capture >> frame;
		if (frame.empty())
			break;

		Sobel(frame, frame, frame.depth(), 1, 0);

		imshow("w", frame);
		if (waitKey(10) > 0)
			break;
	}

	return;
}