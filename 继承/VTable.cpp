//#include <iostream>
//#include <windows.h>
//#include "VTable.h"
//#include "test.h"
//using namespace std;
//
//int main()
//{
//	test1();
//	system("pause");
//	return 0;
//}

////单继承对象模型
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base::func2" << endl;
//	}
//private:
//	int a;
//};
//class Derive :public Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Derive::func1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Derive::func3" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "Derive::func4" << endl;
//	}
//private:
//	int b;
//};
////用函数指针来调用函数，宏定义实现
//typedef void(*FUNC) ();
//
//void PrintVTable(int* VTable)
//{
//	cout << " 虚表地址>" << VTable << endl;
//	//vc里以0来判断结束
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, VTable[i]);
//		FUNC f = (FUNC)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//void Test1()
//{
//	Base b1;     //基类
//	Derive d1;   //子类，如果子类里实现了虚函数重写，则调用重写，否则默认基类
//	//调试窗口里没有显示fun3()&fun4() ,为VC的bug
//	int* VTable1 = (int*)(*(int*)&b1);   //要打印虚表，先得强转，解引用，再强转，拿到地址
//	int* VTable2 = (int*)(*(int*)&d1);
//	PrintVTable(VTable1);              //调用打印函数打印
//	PrintVTable(VTable2);
//}

#include <iostream>
#include <windows.h>
using namespace std;
class Base1
{
public:
	virtual void func1()
	{
		cout << "Base1::func1" << endl;
	}
	virtual void func2()
	{
		cout << "Base1::func2" << endl;
	}
private:
	int b1;
};

class Base2
{
public:
	virtual void func1()
	{
		cout << "Base2::func1" << endl;
	}
	virtual void func2()
	{
	    cout << "Base2::func2" << endl;
	}
private:
	int b2;
};
class Derive : public Base1, public Base2
{
public:
	virtual void func1()
	{
		cout << "Derive::func1" << endl;
	}
    virtual void func3()
	{
		cout << "Derive::func3" << endl;
	}
private:
	int d1;
};
typedef void(*FUNC) ();

void PrintVTable(int* VTable)
{
	cout << " 虚表地址>" << VTable << endl;
	for (int i = 0; VTable[i] != 0; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, VTable[i]);
		FUNC f = (FUNC)VTable[i];
		f();
	}
	cout << endl;
}
void Test1()
{
	Derive d1;
	int* VTable = (int*)(*(int*)&d1);
	PrintVTable(VTable);
	// Base2虚函数表在对象Base1后面
	VTable = (int *)(*((int*)&d1 + sizeof (Base1) / 4));
	PrintVTable(VTable);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}