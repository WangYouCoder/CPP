#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace WY
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		const_iterator begin()const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end()const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val); 
			}
		}

		vector(int n, const T val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e& : v)
			{
				push_back(e);
			}
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);

		}

		vector<T>& operator=(const vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{	
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//错误的，这是浅拷贝
					//memcpy(tmp,_start,sizeof(T) * size());
					for (int i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		//void resize(size_t n,T val = T())
		void resize(size_t n,const T& val = T())
		{
			if (n <= size())
			{
				//删除
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t sz = size();
				//提前保留数据的个数，因为后面可能会改变_start，会对size()函数中的运算造成影响，会在重新对_finish赋值时造成影响

				size_t cp = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[cp];
				if (_start)
				{
					//错误的，这是浅拷贝
					//memcpy(tmp,_start,sizeof(T) * size());
					for (int i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;

				//此处的_finish
				_finish = _start + sz;
				_endofstorage = _start + cp;

				//此处可以替换为
				//reserve( capacity() == 0 ? 4 : capacity() * 2 );
			}

			*_finish = x;
			_finish++;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				//当发生扩容时，因为是重新开辟空间，因此_start会发生改变，而pos还是指向原来的空间，因此需要计算pos与原_start的相对距离，将pos进行更新
				size_t sz = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + sz;
			}

			iterator end = _finish - 1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;
			_finish++;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			while (pos < _finish)
			{
				*pos = *(pos + 1);
				pos++;
			}
			--_finish;

			return pos;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		size_t size()const
		{
			return _finish - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		v.insert(v.begin() + 3,30);
		v.insert(v.begin(), 10);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin() + 3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
