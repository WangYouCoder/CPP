#pragma once
namespace WY
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		
		list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template <class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> iterator;

		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		bool operator!=(const iterator& it) const 
		{
		
			return _node != it._node;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		//++it
		iterator& operator++()
		{
			_node =  _node->_next;
			return *this;
		}

		//it++
		iterator& operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//--it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		iterator& operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};

	struct Pos
	{
		int _a1;
		int _a2;
		Pos(int a1 = 0,int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		Node* _head;
	};

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
			++it;
		}
		cout << endl; 
	}

	void test_list2()
	{
		list<Pos> lt;
		lt.push_back(Pos(10, 20));

		list<Pos>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << (*it)._a1 << "," << (*it)._a2 << endl;
			*it++;
		}
	}

	void Func(const list<int> lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		Func(lt);
	}
}