#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char)
{
	//이미지 리드
	Mat img = imread("test.png");
	//엣지검출?               수직, 수평
	//Sobel(img, img, img.depth(), 1, 0);
	//좌우반전
	flip(img, img, 1);
	//윈도우 창 이름
	namedWindow("test_img", 0);
	//사진 띄우기
	imshow("test_img", img);
	//키 입력을 기다리는
	waitKey(0);
	//키 입력시 사진창 닫음
	destroyAllWindows();
}