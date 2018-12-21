#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	//Vector products
	double va[] = { 1, 2 ,3 };
	double vb[] = { 0, 0 ,1 };
	double vc[3];

	Mat Va(3, 1, CV_64FC1, va);
	Mat Vb(3, 1, CV_64FC1, vb);
	Mat Vc(3, 1, CV_64FC1, vc);

	double res = Va.dot(Vb); //���� Va . Vb -> res ���Ͱ��� ����
	Vc = Va.cross(Vb); //���� Va * Vb -> Vc���Ͱ��� ���ο� ����?
	cout << res << endl << Vc << endl;;

	//Single Matrix operations
	Mat Ma = Mat::eye(3, 3, CV_64FC1);
	double dm[3][3] = { {1,2,3,}, {4,5,6}, {7,8,9} };
	Mat Mb = Mat(3, 3, CV_64F, dm);
	Mat Mc;
	Mc = Mb.t(); // transpose
	cv::Scalar t = trace(Ma); //�밢�� ������ �� ->t.val[0] ��Į�����·� �޾ƾ���
	cout << "treace(Ma) : " << t.val[0] << endl;
	double d = determinant(Ma); //det(Ma) -> d, ad-bc��, �Ľ�
	cout << "determinant(Ma) : " << d << endl;

	double dm2[3][3] = { {1,3,1}, {3,1,2},{1,2,3} };
	Mat Mb2 = Mat(3, 3, CV_64F, dm2);

	Mc = Mb.inv(); //�����
	//invert(Mb2, Mc);

	return 0;
}