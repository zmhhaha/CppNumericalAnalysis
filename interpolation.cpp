#include "stdafx.h"
#include<iostream>
#include<fstream>

using namespace std;

double linear_interpolation(double x_interpolation, double x1, double y1, double x2, double y2, double x3, double y3)
{
	double L1;
	if (x_interpolation<x2)
	{
		L1 = (x_interpolation - x1) / (x2 - x1)*y2 + (x2 - x_interpolation) / (x2 - x1)*y1;
	}
	else
	{
		L1 = (x_interpolation - x2) / (x3 - x2)*y3 + (x3 - x_interpolation) / (x3 - x2)*y2;
	}
	return L1;
}

double parabolic_interpolation(double x_interpolation, double x1, double y1, double x2, double y2, double x3, double y3)
{
	double L2;
	double d12 = x1 - x2;
	double d13 = x1 - x3;
	double d23 = x2 - x3;
	double d21 = x2 - x1;
	double d31 = x3 - x1;
	double d32 = x3 - x2;
	double dx1 = x_interpolation - x1;
	double dx2 = x_interpolation - x2;
	double dx3 = x_interpolation - x3;
	L2 = dx2*dx3 / (d12*d13)*y1 + dx1*dx3 / (d21*d23)*y2 + dx1*dx2 / (d31*d32)*y3;
	return L2;
}

int main()
{
	ofstream fout;
	fout.open("record.dat", ios::trunc); //ios::trunc 如果文件已存在则先删除文件
	fout.close();
	fout.open("record.dat", ios::app); //ios::app 所有输出附加在文件末尾

	double x1, y1;
	double x2, y2;
	double x3, y3;
	cout << "请输入作为插值参照的数据表：（x1，y1）、（x2，y2）、（x3，y3）"<<endl;
	fout << "请输入作为插值参照的数据表：（x1，y1）、（x2，y2）、（x3，y3）" << endl;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << "插值参数表：（" << x1 << "，" << y1 << "）、（" << x2 << "，" << y2 << "）、（" << x3 << "，" << y3 << "）"<<endl;
	fout << "插值参数表：（" << x1 << "，" << y1 << "）、（" << x2 << "，" << y2 << "）、（" << x3 << "，" << y3 << "）" << endl;

	double x;
	cout << "输入要插值的数值:";
	cin >> x;
	fout << "需要插值的数值:" << x << endl;

	double L1 = linear_interpolation(x, x1, y1, x2, y2, x3, y3);

	double L2 = parabolic_interpolation(x, x1, y1, x2, y2, x3, y3);

	cout << "线性插值：" << L1 << endl;
	fout << "线性插值：" << L1 << endl;
	cout << "抛物插值：" << L2 << endl;
	fout << "抛物插值：" << L2 << endl;
	
	fout.close();
	system("pause");
	return 0;
}
