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

	double res = Va.dot(Vb); //내적 Va . Vb -> res 벡터간의 각도
	Vc = Va.cross(Vb); //외적 Va * Vb -> Vc벡터간의 새로운 직교?
	cout << res << endl << Vc << endl;;

	//Single Matrix operations
	Mat Ma = Mat::eye(3, 3, CV_64FC1);
	double dm[3][3] = { {1,2,3,}, {4,5,6}, {7,8,9} };
	Mat Mb = Mat(3, 3, CV_64F, dm);
	Mat Mc;
	Mc = Mb.t(); // transpose
	cv::Scalar t = trace(Ma); //대각선 성분의 합 ->t.val[0] 스칼라형태로 받아야함
	cout << "treace(Ma) : " << t.val[0] << endl;
	double d = determinant(Ma); //det(Ma) -> d, ad-bc행, 렬식
	cout << "determinant(Ma) : " << d << endl;

	double dm2[3][3] = { {1,3,1}, {3,1,2},{1,2,3} };
	Mat Mb2 = Mat(3, 3, CV_64F, dm2);

	Mc = Mb.inv(); //역행렬
	//invert(Mb2, Mc);

	return 0;
}