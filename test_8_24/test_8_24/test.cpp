#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
private:
	int _a;
};
class Date
{
public:
	Date(int year = 1,int month = 1)
	{
		_year = year;
		_month = month;
	}

private:
	int _year;
	int _month;

	A _aa;
};

int main()
{
	Date d;
	return 0;
}