#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int, char)
{
	//at << ptr << data << iterator(like STL)
	//속도 및 난이도 순서

	Mat img = imread("test.png");
	Mat img2 = imread("test.png");

	cout << "픽셀의 사이즈 : " << img.elemSize() << endl;
	cout << "이미지의 채널수 : " << img.channels() << endl;
	cout << "가로의 크기 : " << img.rows << endl;
	cout << "가로의 실제 바이트수 : " << img.step << endl;

	//using data
	for (int i = 0; i < img.rows / 10; i++) {
		for (int j = 0; j < img.cols; j++) {
			unsigned char r, g, b;

			b = img.data[i * img.step + j * img.elemSize() + 0];
			g = img.data[i * img.step + j * img.elemSize() + 1];
			r = img.data[i * img.step + j * img.elemSize() + 2];

			img.data[i * img.step + j * img.elemSize() + 0] = unsigned char(255 - b);
			img.data[i * img.step + j * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[i * img.step + j * img.elemSize() + 2] = unsigned char(255 - r);
		}
	}

	//using at
	for (int i = img.rows / 10 * 2; i < img.rows / 10 * 3; ++i)
	{
		for (int j = 0; j < img.cols; ++j)
		{
			//Vec3b means 'uchar 3ch'
			unsigned char b = img.at< cv::Vec3b>(i, j)[0]; //보통은 다 3채널
			unsigned char g = img.at< cv::Vec3b>(i, j)[1];
			unsigned char r = img.at< cv::Vec3b>(i, j)[2];

			//printf("%d %d %d\n", b, g, r);

			img.at< cv::Vec3b>(i, j)[0] = unsigned char(255 - b); //b
			img.at< cv::Vec3b>(i, j)[1] = unsigned char(255 - g); //g
			img.at< cv::Vec3b>(i, j)[2] = unsigned char(255 - r); //r
		}
	}

	//using ptr
	for (int i = img.rows / 10 * 4; i < img.rows / 10 * 5; i++) {
		cv::Vec3b* ptr = img.ptr< cv::Vec3b >(i);
		for (int j = 0; j < img.cols; j++) {
			unsigned char b1 = (ptr[j][0]);
			unsigned char g1 = (ptr[j][1]); //note!!
			unsigned char r1 = (ptr[j][2]);

			cv::Vec3b bgr = ptr[j];
			unsigned char b2 = (bgr[0]);
			unsigned char g2 = (bgr[1]); //note!!
			unsigned char r2 = (bgr[2]);

			ptr[j] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);
		}
	}
	imshow("img test", img);
	imshow("img2 test", img2);
	waitKey(0);
}