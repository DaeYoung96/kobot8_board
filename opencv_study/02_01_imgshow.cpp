#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char)
{
	//�̹��� ����
	Mat img = imread("test.png");
	//��������?               ����, ����
	//Sobel(img, img, img.depth(), 1, 0);
	//�¿����
	flip(img, img, 1);
	//������ â �̸�
	namedWindow("test_img", 0);
	//���� ����
	imshow("test_img", img);
	//Ű �Է��� ��ٸ���
	waitKey(0);
	//Ű �Է½� ����â ����
	destroyAllWindows();
}