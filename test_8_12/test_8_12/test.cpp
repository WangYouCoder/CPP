#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#define N 10

struct SeqList
{

	int& at(int i)
	{
		return a[i];
	}

	int a[N];
	int size;
};

//int main()
//{
//	SeqList s;
//
//	for (int i = 0; i < N; i++)
//	{
//		s.at(i) = i;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << s.at(i) << " ";
//	}
//}


int main()
{
	int a = 10;
	int& b = a;
	cout << a << endl;
	cout << b << endl;

	b = 20;
	cout << a << endl;
	cout << b << endl;
	return 0;
}