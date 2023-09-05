#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace WY
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const WY::string& s);
        friend istream& operator>>(istream& _cin, WY::string& s);

    public:
        typedef char* iterator;
        typedef const char* const_iterator;

    public:
        string(const char* str = "");

        string(const string& s);

        string& operator = (const string& s);

        ~string();
            //////////////////////////////////////////////////////////////
            // iterator
        iterator begin();
        const_iterator begin()const;

        iterator end();

        const_iterator end()const;
            /////////////////////////////////////////////////////////////

            // modify

        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear();

        void swap(string& s);

        const char* c_str()const;



        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const;

        size_t capacity()const;

        bool empty()const;

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);



        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index);

        const char& operator[](size_t index)const;



        /////////////////////////////////////////////////////////////

        //relational operators

        bool operator<(const string& s);

        bool operator<=(const string& s);

        bool operator>(const string& s);

        bool operator>=(const string& s);

        bool operator==(const string& s);

        bool operator!=(const string& s);



        // ����c��string�е�һ�γ��ֵ�λ��

        size_t find(char c, size_t pos = 0) const;

        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��

        size_t find(const char* s, size_t pos = 0) const;

        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

        void insert(size_t pos, char c);

        void insert(size_t pos, const char* str);

        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
        void erase(size_t pos, size_t len = npos);

    private:
        char* _str;
        size_t _capacity;
        size_t _size;

        const static size_t npos;
    };

    ostream& operator<<(ostream& _cout, const WY::string& s);
    istream& operator>>(istream& _cin, WY::string& s);

    void test_string1();
    void test_string2();
    void test_string3();
    void test_string4();
    void test_string5();
    void test_string6();
};