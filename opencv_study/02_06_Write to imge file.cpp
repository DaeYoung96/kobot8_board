#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("test.png");
	imshow("test", img);

	//imwrite("���ο� �����̸�", �ҷ��� �̹���)
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
	//open("�����̸�", �ڵ�, ������, ���� ���μ��� ũ��, ���-�÷�)
	outvideo.open("outtest.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 60, s, true);

	//file open check
	if (!video.isOpened()) {
		cout << "���� ������ �����ϴ�." << endl;
		return 0;
	}

	while (1) {
		if (frame.empty()) //���̻� ���� �������� ������ ����
			break;
		video >> frame;

		imshow("test_video", frame);

		outvideo << frame;

		if (waitKey(10) == 27)
			break;
	}
	return 0;
}