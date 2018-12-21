#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("test.png");
	imshow("test", img);

	//imwrite("새로운 파일이름", 불러올 이미지)
	/*
	imwrite("new_test.jpg", img);

	vector<Mat> rgbMat(3);
	split(img, rgbMat);
	imwrite("r.jpg", rgbMat[2]);
	imwrite("g.jpg", rgbMat[1]);
	imwrite("b.jpg", rgbMat[0]);
	*/

	VideoCapture video("cat_test.avi");
	//VideoCapture video(0);
	Mat frame;
	VideoWriter outvideo;
	Size s = Size((int)video.get(CAP_PROP_FRAME_WIDTH),
		(int)video.get(CAP_PROP_FRAME_HEIGHT));
	//open("파일이름", 코덱, 프레임, 비디오 가로세로 크기, 흑백-컬러)
	outvideo.open("outtest.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 60, s, true);

	//file open check
	if (!video.isOpened()) {
		cout << "비디오 파일이 없습니다." << endl;
		return 0;
	}

	while (1) {
		if (frame.empty()) //더이상 읽을 프레임이 없으면 종류
			break;
		video >> frame;

		imshow("test_video", frame);

		outvideo << frame;

		if (waitKey(10) == 27)
			break;
	}
	return 0;
}