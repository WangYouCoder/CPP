#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"

const size_t WY::string::npos = -1;


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
	_str[0] = '\0';
}

void WY::string::swap(string& s)
{
	char* tmp = new char[_capacity + 1];
	strcpy(tmp, _str);
	strcpy(_str, s._str);
	strcpy(s._str, tmp);
}

size_t WY::string::size()const
{
	return _size;
}

size_t WY::string::capacity()const
{
	return _capacity;
}

bool WY::string::empty()const
{
	return _size == 0;
}

void WY::string::insert(size_t pos, char c)
{
	assert(pos >= 0);
	if (_size == _capacity)
	{
		reserve(_capacity * 2);
	}

	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		end--;
	}
	_str[pos] = c;
	_size++;
}

void WY::string::insert(size_t pos, const char* str)
{
	assert(pos >= 0);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}

	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end + len - 1] = _str[end - 1];
		end--;
	}
	strncpy(_str + pos, str, len);
	_size += len;
}


void WY::string::erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (len == npos ||pos + len > _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		size_t begin = pos + len;
		while (begin <= _size)
		{
			_str[pos++] = _str[begin++];
		}
		_size -= len;
	}
}

void WY::string::resize(size_t n, char c)
{
	if (n <= _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		reserve(n);
		while (_size < n)
		{
			_str[_size++] = c;
		}
		_str[_size] = '\0';
	}
}

WY::string::iterator WY::string::begin()
{
	return _str;
}

WY::string::const_iterator WY::string::begin()const
{
	return _str;
}

WY::string::iterator WY::string::end()
{
	return _str + _size;
}

WY::string::const_iterator WY::string::end()const
{
	return _str + _size;
}

ostream& WY::operator<<(ostream& _cout, const WY::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		_cout << s[i];
	}
	return _cout;
}

istream& WY::operator>>(istream& _cin, WY::string& s)
{
	char ch = _cin.get();
	while (ch != ' ' && ch != '\n')
	{
		s += ch;
		ch = _cin.get();
	}
	return _cin;
}

bool WY::string::operator<(const string& s)
{
	return strcmp(_str, s._str) < 0;
}

bool WY::string::operator==(const string& s)
{
	return strcmp(_str, s._str) == 0;
}

bool WY::string::operator<=(const string& s)
{
	return (*this < s) || (*this == s);
}

bool WY::string::operator>(const string& s)
{
	return !(*this <= s);
}

bool WY::string::operator>=(const string& s)
{
	return !(*this < s);
}

bool WY::string::operator!=(const string& s)
{
	return !(*this == s);
}

size_t WY::string::find(char c, size_t pos) const
{
	for (size_t i = pos; i < size(); i++)
	{
		if (_str[i] == c)
			return i;
	}
	
	return npos;
}

size_t WY::string::find(const char* s, size_t pos) const
{
	const char* p = strstr(_str + pos, s);
	if (p)
	{
		return p - _str;
	}
	else
	{
		return npos;
	}
}
