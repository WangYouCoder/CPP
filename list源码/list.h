#pragma once
#include<iostream>
using namespace std;

namespace WY
{
	//在 list_node<T> 中加<T>可以理解为 list_node 是一个类，比如之前模拟实现的 vector,在使用时都会写成 vector<T>,目前就可以近似的这么理解

	//在 list 中存放的都是一个一个的节点,而一个节点又包含数据域以及指针域,因此需要对节点进行封装,便于存储到 list 中
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

	// 因为 list 中迭代器的解引用以及 ++ 都无法像 vector 和 string 中那样使用,因此需要对迭代器进行封装实现这些功能
	// 迭代器本质上也是在对节点进行运算，因此它的成员也是 Node*,参考 list<int>::iterator it = lt.begin(),lt.begin()返回的就是一个节点的地址
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
		// 只在类域里面使用，所以设置为私有，在 class 默认为私有，在 struct 中默认为公有
		typedef struct list_node<T> Node;

	public:

		// 在类域外面也需要使用，因此要放到 public 里面
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
	//	// 加 typename 的原因：编译器在编译时只会对实例化的模板进行编译，而这里的 list<T> 并没有被实例化，参数里的 list<T> 在进行传参时会被实例化
	//	// 而函数体内的并没有进行实例化，所以在编译时编译器无法识别 const_iterator 是内嵌类型还是静态成员变量，所以在编译是会报错
	//	// 而加了 typename，会让编译器跳过这个检查阶段，我目前的理解是在用 lt.begin() 对 it 进行赋值时才会对前面的 list<T> 进行实例化（待查证）
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



