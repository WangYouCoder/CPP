#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int& ra = a;
//
//	++(*pa);
//	++ra;
//	return 0;
//}
#define Add(a,b) ((a) + (b))

//inline void Fun(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 10, b = 20;
//	Fun(a, b);
//	int c = Add(a, b);
//	cout << c << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10, b = 20;
//	int tmp = a;
//	a = b;
//	b = tmp;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = b;
//	//auto d;    无法通过编译，使用auto定义变量时必须对其进行初始化
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}
#include"fun.h"

//int main()
//{
//	int x = 10;
//
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}
//
//void f(int)
//{
//    cout << "f(int)" << endl;
//}
//void f(int*)
//{
//    cout << "f(int*)" << endl;
//}
//int main()
//{
//    f(0);
//    f(NULL);
//    f((int*)NULL);
//    return 0;
//}

//struct Stack
//{
//	void push()
//	{
//
//	}
//	int* a;
//	int top;
//	int capacity;
//};
#include<assert.h>
class Stack
{
public:
	void Init()
	{
		assert(a);
		a = nullptr;
		top = capacity = 0;
	}

	void push(int x)
	{
		if (top == capacity)
		{
			size_t newcapacity = capacity == 0 ? 4 : capacity * 2;
			int* tmp = (int*)realloc(a,sizeof(int) * newcapacity);
			if (tmp == nullptr)
				return;
			a = tmp;
			capacity = newcapacity;
		}
		a[top++] = x;
	}

	int Top()
	{
		return a[top - 1];
	}
private:
	int* a;
	int top;
	int capacity;
};

int main()
{
	Stack st;
	st.Init();
	st.push(1);
	st.push(2);
	st.push(3);

	cout << st.Top() << endl;

	return 0;
}