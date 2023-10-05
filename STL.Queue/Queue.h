#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

namespace WY
{
	template<class T, class Container>
	class Queue
	{
	public:

		void push(const T& x)
		{
			_con.push_pop(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_Queue1()
	{
		Queue<int, list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}
