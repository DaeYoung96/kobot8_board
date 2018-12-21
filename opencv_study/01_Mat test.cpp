#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	//ones == ����� ������ ���ÿ� ��簪�� 1�� ����
	Mat m = Mat::ones(3, 3, CV_64F);
	m = m * 3;
	cout << m << endl;

	double dm[3][3] = { {1,2,1}, {0,1,1}, {1,0,0} };
	Mat m2 = Mat(3, 3, CV_64F, dm); //�ܺ��� �迭 �����ؼ� ����
	cout << m2 << endl;
	//����
	cout << m + m2 << endl;

	//����
	cout << m - m2 << endl;

	//����
	cout << m * m2 << endl;
	//�� �ڸ����� ����
	cout << m.mul(m2) << endl << endl;

	//??
	//cout << m / m2 << endl;

	//�����
	cout << m2.inv() << endl;

	//Ʈ��������
	cout << m2.t() << endl;

	//m2 = m+m2 ��� dm���� �ٲ��
	return 0;
}