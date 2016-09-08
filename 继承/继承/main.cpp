#include <iostream>
#include <Windows.h>
//
using namespace std;
//
//class A
//{
//public:
//	A()
//		:a(1)
//	{}
//	virtual void f1()
//	{}
//private:
//	int a;
//};
//
//class B1 :virtual public A     //解决二义性
//{
//public:
//	B1()
//		:b1(2)
//	{}
//	virtual void f1()
//	{}
//	virtual void f2()
//	{}
//private:
//	int b1;
//};
//
//class B2:virtual public A
//{
//public:
//	B2()
//		:b2(2)
//	{}
//	virtual void f1()
//	{}
//	virtual void f2()
//	{}
//private:
//	int b2;
//};
//
//class C: public B1, public B2
//{
//public:
//	C()
//		:c(4)
//	{}
//	virtual void f1()
//	{}
//	virtual void f3()
//	{}
//	virtual void f4()
//	{}
//private:
//	int c;
//};
//
//int main()
//{
//	C c;
//	cout << sizeof(c) << endl;
//	system("pause");
//	return 0;
//}

class A
{
public:
	A()
		:a(1)
	{}
	//virtual void f1(){
		//cout << "hello" << endl;
	//}
	 void f1(){}
private:
	int a;
	//B b;
};

class B1: public A
{
public:
	B1()
		:a(1)
	{}
    void f1(){
		//cout << "hello" << endl;
	}
private:
	int a;
	//b b;
};

class B: virtual public A
{
public:
	B()
		:b(2)
	{}
	virtual void f1(){
		//cout << "world" << endl;
	}
	virtual void f2(){}
	virtual void f3(){}
	virtual void f4(){}
private:
	int b;
	//B b;
};


int main()
{
	B1 b;
	b.f1();


	//char c[] = { { 0 }, { 1 }, { 2 }};
	//char c[] = { { 0 }, { 1 }, { 2 } };

	//char c = 57;
	//printf("%c.\n",c);
	//char c[4] = "123";
	//char c[][3] = { { "1"},  "0"  };
	//char c[][3] = { { "0" }, { "1","2" } };
	//cout << sizeof(c) << endl;
	//cout<< strlen(c[1]) << endl;
	/*int i = 1 << 32;

	printf("%d\n",i);*/
	/*char b[] = "hello";
	b[1] = '1';
	cout << b << endl;
	char *p = "hello";
	char *a;
	a = p;*/
	//a[1] = 'a';
	system("pause");
	return 0;
}
