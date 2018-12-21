#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int, char)
{
	//���� ���� ����
	VideoCapture video("cat_test.mp4");
	VideoCapture cam(0); //��ǻ�Ϳ� �޸� ��ķ ����
	Mat frame;

	//������ �ִ��� üũ
	if (!video.isOpened())
	{
		printf("AVI file can not open.\n");
		return 0;
	}

	//create window
	namedWindow("test");

	while (1)
	{
		//������ �����ӿ� �־��ְ�
		cam >> frame;
		if (frame.empty()) //���̻� ���� �������� ������ ����
			break;

		//processing example
		//Sobel(frame, frame, frame.depth(), 1, 0);
		////////////////////

		//â �����ִ°�
		imshow("test", frame);
		if (waitKey(10) > 0)
			break;
	}
}