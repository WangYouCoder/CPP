#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
#include"list.h"

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_front(10);
	lt.push_front(20);
	lt.push_front(30);
	lt.push_front(40);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	auto pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end())
	{
		lt.erase(pos);
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void testOP()
{
	srand((size_t) time(nullptr));
	vector<int> v;
	list<int> lt;
	const int N = 100000;
	v.reserve(N);

	for (int i = 0; i < N; i++)
	{
		int e = rand();
		v.push_back(e);
		lt.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt.sort();
	int end2 = clock();

	/*cout << "vector:" << end1 - begin1 << endl;
	cout << "list:" << end2 - begin2 << endl;*/

	printf("vector:%d\n", end1 - begin1);
	printf("list:%d\n", end2 - begin2);
}



int main()
{
	//test_list1();
	//test_list2();
	//testOP();

	WY::test_list3();
	return 0;
}