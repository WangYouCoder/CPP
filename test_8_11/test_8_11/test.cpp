#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//C++��׼��������ռ�
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Wang You" << endl;
//}

int rand = 1;

//int main()
//{
//	printf("%d", rand);
//	return 0;
//}



namespace WY
{
	int rand = 1;

	int Add(int a, int b)
	{
		return a + b;
	}

	struct Node
	{
		int data;
		int* next;
	};

	namespace xxx
	{
		int rand = 1;
	}
}

//ȫ��չ��
//using namespace WY;

//����չ��
using WY::Add;

int main()
{
  //�������޶���
	printf("%d", rand);
	printf("%d", WY::rand);
	printf("%d", WY::xxx::rand);
	printf("%d", Add(1,2));

	struct WY::Node node;

	return 0;
}

