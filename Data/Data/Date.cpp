#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	int _month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
	{
		_month[2] = 29;
	}

	return _month[month];
}

Date::Date(int year,  int month, int day)
	:_year(year)
	, _month(month)
	, _day(day)
{
	if (_month < 1 || _month > 12 ||
		_day < 1 || _day > GetMonthDay(_year, _month))
	{
		cout << "日期错误" << endl;
	}
}

Date::Date(const Date& d)
{
	cout << "Date::Date(const Date& d)" << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date()
{
	_year = _month = _day = 0;
}


Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= day;
	}
	_day += day;
	if (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-_day);
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

bool Date::operator>(const Date& d)
{
	if (_year < d._year)
	{
		return false;
	}
	else if (_year == d._year && _month < d._month)
	{
		return false;
	}
	else if (_month == d._month && _day < d._day)
	{
		return false;
	}

	return true;
}

bool Date::operator==(const Date& d)
{
	cout << "bool Date::operator==(const Date& d)" << endl;
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator >= (const Date& d)
{
	return (*this == d) && (*this > d);
}

bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	//int day = 0;
	//day = _day - d._day;
	//while (_month >= d._month)
	//{
	//	_month--;
	//	if (_month > 0)
	//	{
	//		day += GetMonthDay(_year, _month);
	//	}
	//}

	//while (_year > d._year)
	//{
	//	_year--;
	//	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
	//	{
	//		day += 366;
	//	}
	//	else
	//	{
	//		day += 355;
	//	}
	//}
	//return day;

	Date max = *this;
	Date min = d;
	int flag = 1;

	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min < max)
	{
		min++;
		n++;
	}

	return n * flag;
}

void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << endl;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

ostream& operator<<(ostream& out, Date& d)
{
	out << d._year << "年"<< d._month <<"月" <<  d._day;
	return out;
}