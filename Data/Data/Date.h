#pragma once
#include<iostream>
using namespace std;

namespace WY
{
	class Date
	{
	public:
		// 获取某年某月的天数
		int GetMonthDay(int year, int month)
		{
			int _month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
			if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
			{
				_month[2] = 29;
			}

			return _month[month];
		}

		// 全缺省的构造函数
		Date(int year = 1900, int month = 1, int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{}

		// 拷贝构造函数
		// d2(d1)
		Date(const Date& d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		// 赋值运算符重载
		//d2 = d3 -> d2.operator=(&d2, d3)
		Date& operator=(const Date& d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;

			return *this;
		}

		// 析构函数
		~Date();

		// 日期+=天数
		Date& operator+=(int day)
		{
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

		// 日期+天数
		Date operator+(int day)
		{
			Date tmp(*this);
			tmp += day;
			return tmp;
		}

		// 日期-天数
		Date operator-(int day)
		{
			Date tmp(*this);
			tmp -= day;
			return tmp;
		}

		// 日期-=天数
		Date& operator-=(int day)
		{
			_day -= day;
			if (_day <= 0)
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

		// 前置++
		Date& operator++()
		{
			++_day;
			return *this;
		}

		// 后置++
		Date operator++(int)
		{
			Date tmp(*this);
			++_day;
			return tmp;
		}

		// 后置--
		Date operator--(int)
		{
			Date tmp(*this);
			--_day;
			return tmp;
		}

		// 前置--
		Date& operator--()
		{
			--_day;
			return *this;
		}

		// >运算符重载
		bool operator>(const Date& d)
		{
			if (_year > d._year)
			{
				if (_month > d._month)
				{
					if (_day > d._day)
					{
						return true;
					}
				}
			}
			return false;
		}

		// ==运算符重载
		bool operator==(const Date& d)
		{
			return _year == d._year
				&& _month == d._month
				&& _day == d._day;
		}

		// >=运算符重载
		bool operator >= (const Date& d)
		{
			return (*this == d) && (*this > d);
		}

		// <运算符重载
		bool operator < (const Date& d)
		{
			return !(*this >= d);
		}

		// <=运算符重载
		bool operator <= (const Date& d)
		{
			return !(*this > d);
		}

		// !=运算符重载
		bool operator != (const Date& d)
		{
			return !(*this == d);
		}

		// 日期-日期 返回天数
		int operator-(const Date& d)
		{
			int day = 0;
			day = _day - d._day;
			while (_month >= d._month)
			{
				_month--;
				if (_month > 0)
				{
					day += GetMonthDay(_year, _month);
				}
			}

			while (_year > d._year)
			{
				_year--;
				if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
				{
					day += 366;
				}
				else
				{
					day += 355;
				}
			}

			return day;
		}
	private:
		int _year;
		int _month;
		int _day;
	};
}