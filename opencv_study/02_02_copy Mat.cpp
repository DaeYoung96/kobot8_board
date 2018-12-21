#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char)
{
	//�̹��� ����
	Mat img = imread("test.png");
	Mat img2;

	//���� ����(�װ�Ƽ��)
	bitwise_not(img, img2);

	//clone ����
	Mat img3 = img.clone();

	//�簢��
	Rect r(img.cols / 8, img.rows / 8, img.cols / 2, img.rows / 2);
	cout << r << endl;

	//�簢�� ũ�⸸ŭ
	Mat img4 = img(r).clone();

	//copyto
	Mat cimg;
	img.copyTo(cimg);

	//copyto#2
	Mat cimg2(Size(img.cols, img.rows * 2), img.type());
	cimg2.setTo(255); //������� �ʱ�ȭ
	img.copyTo(cimg2(Range(0, img.rows), Range::all()));
	img2.copyTo(cimg2(Range(img.rows, img.rows * 2), Range::all()));

	//�������� ����
	Mat roi(img, r);
	bitwise_not(roi, roi);
	//���� ����
	imshow("img", img);
	imshow("cimg2", cimg2);
	imshow("roi", roi);
	//Ű �Է��� ��ٸ���
	waitKey(0);
	//Ű �Է½� ����â ����
	destroyAllWindows();
}