#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	//ones == 행렬의 생성과 동시에 모든값을 1로 설정
	Mat m = Mat::ones(3, 3, CV_64F);
	m = m * 3;
	cout << m << endl;

	double dm[3][3] = { {1,2,1}, {0,1,1}, {1,0,0} };
	Mat m2 = Mat(3, 3, CV_64F, dm); //외부의 배열 참조해서 생성
	cout << m2 << endl;
	//덧셈
	cout << m + m2 << endl;

	//뺄셈
	cout << m - m2 << endl;

	//곱셉
	cout << m * m2 << endl;
	//각 자리마다 곱셉
	cout << m.mul(m2) << endl << endl;

	//??
	//cout << m / m2 << endl;

	//역행렬
	cout << m2.inv() << endl;

	//트랜스포즈
	cout << m2.t() << endl;

	//m2 = m+m2 결과 dm값도 바뀐다
	return 0;
}