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
}

int main()
{
	//test1();
	test2();
	return 0;
}