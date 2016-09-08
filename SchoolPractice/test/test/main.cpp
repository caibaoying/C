#include <iostream>
#include <windows.h>
using namespace std;
////
////class Node
////{
////public:
////	Node()
////	{
////		printf("   qweqrerwr");
////	}
////	Node(int data)
////		:_data(data)
////	{
////		printf("   dfsfgsg");
////	}
////private:
////	int _data;
////	//Node* _next;
////};
////
////int fun()
////{}
////
////double fun()
////{}
////
////int main()
////{
////	Node a = Node();
////	return 0;
////}
//
//#include <stdio.h>
//
//void Swap(int& l, int& r)
//{
//	int temp = l;
//	l = r;
//	r = temp;
//} 
//void Test()
//{
//	int c = 0;
//	int* p = &c;
//	//cout << *p << endl;
//	int& a = *p;
//	int b = 2;
//	cout << a << "<-->" << b << endl;
//	Swap(a, b);
//	cout << a << "<-->" << b << endl;
//}
//
////int main(void)
////{
////	/*int x, y;
////	x = 0;
////	while (x < 10)
////	{
////		y = x*x;
////		printf("%d\t%d\n",x,y);
////		x += 1;
////	}
////	system("pause");*/
////
////	/*int a = 123455678;
////	float b = a;
////	printf("%f", b);*/
////
////	/*int a = 2, b = 3;
////	int *c = &a;
////	printf("%d    %d",*c, c);*/
////
////	/*double a = 1.0;
////	double *b = &a;
////	printf("%d", sizeof(b));*/
////	/*int a[5] = {1,2,3,4,5};
////	int *b = a;
////	printf("%d, %d", *(b+1), *((int*)b+4));
////	system("pause");*/
////
////	
////}
//
////void fun()
////{
////	int a = 1;
////	double b = 2.0;
////
////	int& c = a;
////	double& d = b;
////	cout << sizeof(c) << ":"<<sizeof(d) << endl;
////}
//class A
//{
//	char ch;
//	double d;
//};
//class B
//{
//	char ch1;
//	A a;
//	char ch2;
//};
//int main()
//{
//	//Test();
//	//fun();
//
//	cout<<sizeof(A)<<endl;
//	cout << sizeof(B) << endl;
//	system("pause");
//}

class A
{
public:
	virtual int f1();
	virtual int f2();
private:
	int a;
};

class B :virtual public A
{
public:
	virtual int f1();
	virtual int f3();
	virtual int f4();
private:
	int b;
};

int main()
{
	B b;
	system("pause");
}