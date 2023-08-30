#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

//void test1()
//{
//	Date d1(2023, 8, 26);
//	Date d2 = d1;
//	d2.Print();
//
//	Date d3(2023, 8, 31);
//	Date ret1 = d3++;
//	ret1.Print();
//	d3.Print();
//
//	/*int day = d3 - d1;
//	cout << day << endl;*/
//}

void test2()
{
	Date d1(2023, 8, 26);
	Date d2(2023, 8, 27);

	cout << d1 - d2 << endl;

	cout << d1 << endl;
}

void test3()
{
	Date d1(2023, 8, 30);
	Date d3 = d1;

	//Date* ptr = nullptr;
	//ptr->Print();
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}