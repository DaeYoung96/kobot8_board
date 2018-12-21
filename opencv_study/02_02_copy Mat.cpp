#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char)
{
	//이미지 리드
	Mat img = imread("test.png");
	Mat img2;

	//사진 반전(네거티브)
	bitwise_not(img, img2);

	//clone 복사
	Mat img3 = img.clone();

	//사각형
	Rect r(img.cols / 8, img.rows / 8, img.cols / 2, img.rows / 2);
	cout << r << endl;

	//사각형 크기만큼
	Mat img4 = img(r).clone();

	//copyto
	Mat cimg;
	img.copyTo(cimg);

	//copyto#2
	Mat cimg2(Size(img.cols, img.rows * 2), img.type());
	cimg2.setTo(255); //흰색으로 초기화
	img.copyTo(cimg2(Range(0, img.rows), Range::all()));
	img2.copyTo(cimg2(Range(img.rows, img.rows * 2), Range::all()));

	//참조형식 생성
	Mat roi(img, r);
	bitwise_not(roi, roi);
	//사진 띄우기
	imshow("img", img);
	imshow("cimg2", cimg2);
	imshow("roi", roi);
	//키 입력을 기다리는
	waitKey(0);
	//키 입력시 사진창 닫음
	destroyAllWindows();
}