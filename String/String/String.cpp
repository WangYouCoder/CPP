#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"

//构造
WY::string::string(const char* str)
	:_size(strlen(str))
	,_capacity(strlen(str))
{
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

//拷贝构造
WY::string::string(const string& s)
{
	_str = new char[s._capacity + 1];
	strcpy(_str, s._str);
	_capacity = s._capacity;
	_size = s._size;
}

WY::string& WY::string::operator = (const string& s)
{
	_str = new char[s._capacity + 1];
	strcpy(_str, s._str);
	_capacity = s._capacity;
	_size = s._size;

	return *this;
}

//析构
WY::string::~string()
{
	delete[] _str;
	_str = nullptr;
	_capacity = _size = 0;
}

WY::string::iterator WY::string::begin()
{
	return _str;
}

WY::string::iterator WY::string::end()
{
	return _str + _size;
}

char& WY::string::operator[](size_t index)
{
	return _str[index];
}

const char& WY::string::operator[](size_t index)const
{
	return _str[index];
}

//扩容
void WY::string::reserve(size_t n)
{
	if (_capacity < n)
	{
		_capacity = n;
		char* tmp = new char[n + 1];
		strcpy(tmp, _str);
		delete[] _str;

		_str = tmp;
	}
}

void WY::string::push_back(char c)
{
	if (_size == _capacity)
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	}

	_str[_size] = c;
	_size++;
	_str[_size] = '\0';
}

void WY::string::append(const char* str)
{
	int len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}

	strcpy(_str + _size, str);
	_size +=len;
}

const char* WY::string::c_str()const
{
	return _str;
}

WY::string& WY::string::operator+=(char c)
{
	push_back(c);
	return *this;
}

WY::string& WY::string::operator+=(const char* str)
{
	append(str);
	return *this;
}

void WY::string::clear()
{
	_str[0] = '/0';
}

