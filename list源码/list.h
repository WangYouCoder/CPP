#pragma once
#include<iostream>
using namespace std;

namespace WY
{
	//�� list_node<T> �м�<T>�������Ϊ list_node ��һ���࣬����֮ǰģ��ʵ�ֵ� vector,��ʹ��ʱ����д�� vector<T>,Ŀǰ�Ϳ��Խ��Ƶ���ô���

	//�� list �д�ŵĶ���һ��һ���Ľڵ�,��һ���ڵ��ְ����������Լ�ָ����,�����Ҫ�Խڵ���з�װ,���ڴ洢�� list ��
	template <class T>
	struct list_node
	{
		T _data;
		struct list_node<T>* _next;
		struct list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	// ��Ϊ list �е������Ľ������Լ� ++ ���޷��� vector �� string ������ʹ��,�����Ҫ�Ե��������з�װʵ����Щ����
	// ������������Ҳ���ڶԽڵ�������㣬������ĳ�ԱҲ�� Node*,�ο� list<int>::iterator it = lt.begin(),lt.begin()���صľ���һ���ڵ�ĵ�ַ
	template <class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;

		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node; 
		}
	};

	//template <class T>
	//struct __list_const_iterator
	//{
	//	typedef struct list_node<T> Node;
	//	typedef __list_const_iterator<T> self;

	//	Node* _node;

	//	__list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}

	//	self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	self operator++(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	self operator--(int)
	//	{
	//		self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const self& s)
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const self& s)
	//	{
	//		return _node == s._node;
	//	}
	//};

	
	template<class T>
	class list
	{
		// ֻ����������ʹ�ã���������Ϊ˽�У��� class Ĭ��Ϊ˽�У��� struct ��Ĭ��Ϊ����
		typedef struct list_node<T> Node;

	public:

		// ����������Ҳ��Ҫʹ�ã����Ҫ�ŵ� public ����
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef __list_const_iterator<T> const_iterator;

		const_iterator begin()const
		{
			return _head->_next;
		}

		const_iterator end()const
		{
			return _head;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		
		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		list(const list<T>& lt)
		{
			empty_init();

			for (auto e : lt)
			{
				push_back(e);
			}
		}

		////lt2 = lt1
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (lt != *this)
		//	{
		//		clear();
		//		for (auto e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		void swap(const list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;

			//_head->_prev = newnode;
			//newnode->_next = _head;

			//tail->_next = newnode;
			//newnode->_prev = tail;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);

			Node* prev = pos._node->_prev;

			// prev  newnode  pos._node
			newnode->_next = pos._node;
			pos._node->_prev = newnode;

			newnode->_prev = prev;
			prev->_next = newnode;
			_size++;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next->_next;
			next ->_prev = prev;
			_size--;

			return iterator(next);
		}

	private:
		Node* _head;
		size_t _size;
	}; 

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//void Print_list(const list<int>& lt)
	//{
	//	list<int>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//}

	//template<typename T>
	//void Print_list(const list<T>& lt)
	//{
	//	// �� typename ��ԭ�򣺱������ڱ���ʱֻ���ʵ������ģ����б��룬������� list<T> ��û�б�ʵ������������� list<T> �ڽ��д���ʱ�ᱻʵ����
	//	// ���������ڵĲ�û�н���ʵ�����������ڱ���ʱ�������޷�ʶ�� const_iterator ����Ƕ���ͻ��Ǿ�̬��Ա�����������ڱ����ǻᱨ��
	//	// ������ typename�����ñ���������������׶Σ���Ŀǰ����������� lt.begin() �� it ���и�ֵʱ�Ż��ǰ��� list<T> ����ʵ����������֤��
	//	typename list<T>::const_iterator it = lt.begin();
	//	while (it != lt.end())
	//	{
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//}

	template<typename Container>
	void Print_container(const Container& con)
	{
		typename Container::const_iterator it = con.begin();
		while (it != con.end())
		{
			cout << *it << " ";
			++it;
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
		lt.push_back(5);

		//Print_list(lt);
		Print_container(lt);
	}
}



