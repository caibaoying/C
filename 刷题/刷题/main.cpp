#include <iostream>
#include <assert.h>
#include <queue>
#include <Windows.h>
#include "输入输出问题.h"
using namespace std;

//struct BinaryTreeNode
//{
//	int _data;
//	BinaryTreeNode* _left;
//	BinaryTreeNode* _right;
//
//	BinaryTreeNode(int data)
//	{
//		_data = data;
//	}
//};
//
////构造一棵二叉树
//class BinaryTree
//{
//public:
//	BinaryTree()
//	:_root(NULL)
//	{}
//	BinaryTree(const char* a, int size)
//	{
//		int index = 0;
//		_root = _Create(a, size, index);
//	}
//
//	//求二叉树的宽度】宽度就是二叉树每层节点个数的最大值，只看一层，不用相加；
//	int width()
//	{
//		BinaryTreeNode* cur = _root;
//		if (NULL == _root)
//		{
//			return -1;
//		}
//		queue<BinaryTreeNode*> _queue;
//		_queue.push(cur);
//		int nLastLevelWidth = 1;
//		int nCurLevelWidth = 0;
//		int nWidth = 0;
//
//		int ntmpLastLevel = 0;
//		while (!_queue.empty())
//		{
//			ntmpLastLevel = nLastLevelWidth;
//			while (ntmpLastLevel != 0)
//			{
//				BinaryTreeNode* tmp = _queue.front();
//				_queue.pop();
//				if (tmp->_left)
//					_queue.push(tmp->_left);
//				if (tmp->_right)
//					_queue.push(tmp->_right);
//				--ntmpLastLevel;
//			}
//
//			nCurLevelWidth = _queue.size();
//			nWidth = nLastLevelWidth < nCurLevelWidth ? nCurLevelWidth : nLastLevelWidth;
//			nLastLevelWidth = nCurLevelWidth;
//		}
//		return nWidth;
//	}
//
//	~BinaryTree()
//	{}
//protected:
//	BinaryTreeNode* _Create(const char* a, int size,int index)
//	{
//		assert(a);
//		BinaryTreeNode* root = NULL;
//		if (index < size && a[index] != '#')
//		{
//			root = new BinaryTreeNode(a[index]);
//			root->_left = _Create(a, size, ++index);
//			root->_right = _Create(a, size, ++index);
//		}
//		return root;
//	}
//private:
//	BinaryTreeNode* _root;
//};
//
//void test()
//{
//	char arr[] = { '1', '2', '#', '#', '3', '4', '#', '#', '5', '6' };
//	BinaryTree bt(arr, 10);
//	cout<<bt.width()<<endl;
//}
//
//class A
//{
//public:
//	void fun()const  // const 调用const，非const调用非const
//	{
//		printf("A123\n");
//	}
//
//	virtual void fun()
//	{
//		printf("A456\n");
//	}
//	virtual ~A()
//	{
//		printf("~A");
//	}
//};
//
//class B :public A
//{
//public:
//	void fun()
//	{
//		printf("B");
//	}
//	virtual ~B()
//	{
//		printf("~B");
//	}
//};
class A
{
public:
	void test()
	{
		static int i;
		printf("abc\n");
	}

	static void fun();

	void fun2()
	{
		fun();
	}
};
void A::fun()
{
	//test();
}

int main()
{
	//const int i = 0;
	//static int b;
	A::fun();
	//fun2();
	/*A* p = new B();
	A a;
	B b;
	cout << sizeof(a) << endl; 
	cout << sizeof(b) << endl;
	cout << sizeof(p) << endl;*/
	/*p->fun();
	p->~A();
	const int a = 0;
	int b = a;
	cout << b;
	A a;
	a.fun();
	//test();
	input();*/
	system("pause");
	return 0;
}