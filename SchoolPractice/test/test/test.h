#include <iostream>

using namespace std;

class A
{
public:
	virtual int f1();
	virtual int f2();
private:
	int a;
};

class B:virtual public A
{
public:
	virtual int f1();
	virtual int f3();
	virtual int f4();
private:
	int b;
};