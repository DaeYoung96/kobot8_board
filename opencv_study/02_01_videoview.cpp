#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int, char)
{
	//비디오 파일 열기
	VideoCapture video("cat_test.mp4");
	VideoCapture cam(0); //컴퓨터에 달린 웹캠 동장
	Mat frame;

	//파일이 있는지 체크
	if (!video.isOpened())
	{
		printf("AVI file can not open.\n");
		return 0;
	}

	//create window
	namedWindow("test");

	while (1)
	{
		//영상을 프레임에 넣어주고
		cam >> frame;
		if (frame.empty()) //더이상 읽을 프레임이 없으면 종류
			break;

		//processing example
		//Sobel(frame, frame, frame.depth(), 1, 0);
		////////////////////

		//창 보여주는것
		imshow("test", frame);
		if (waitKey(10) > 0)
			break;
	}
}