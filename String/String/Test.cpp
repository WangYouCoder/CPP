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

void WY::test_string2()
{
    string s("hello world");
    s.insert(0, 'x');
    cout << s.c_str() << endl;

    string s1("hello world");
    s1.insert(0, "xxx");
    cout << s1.c_str() << endl;

    s.erase(0, 1);
    cout << s.c_str() << endl;

    s1.erase(0, 3);
    cout << s1.c_str() << endl;

    s1.erase(1);
    cout << s1.c_str() << endl;

}

void WY::test_string3()
{
    string s("hello world");
    s.resize(5);
    cout << s.c_str() << endl;

    s.resize(20,'x');
    cout << s.c_str() << endl;
}

void WY::test_string4()
{
    string s;
    cin >> s;
    cout << s << endl;
}

void WY::test_string5()
{
    string s("hello world");

    string s1("hello world");
    cout << (s == s1) << endl;

    string s2("hello");
    cout << (s == s2) << endl;

    string s3("a");
    string s4("b");
    cout << (s3 < s4) << endl;
}

void WY::test_string6()
{
    string s("hello world");
    size_t pos = s.find('w');
    cout << pos << endl;
}

int main()
{
	//WY::test_string1();
    //WY::test_string2();
    //WY::test_string3();
    //WY::test_string4();
    //WY::test_string5();
    WY::test_string6();
	return 0;
}