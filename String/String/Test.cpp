#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"

void WY::test_string1()
{
    string s("hello world");
    cout << s.c_str() << endl;

    string s1(s);
    cout << s1.c_str() << endl;

    string s2;
    s2 = s;
    cout << s2.c_str() << endl;

    s.push_back('x');
    cout << s.c_str() << endl;

    s1.append("xxx");
    cout << s1.c_str() << endl;
    
    s2 += 'x';
    cout << s2.c_str() << endl;

    s2 += "xxx";
    cout << s2.c_str() << endl;

}

int main()
{
	WY::test_string1();
	return 0;
}