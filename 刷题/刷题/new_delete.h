#pragma once

#include <iostream>
using namespace std;
/*********************************************************************
1:new,new[],delete,delete[]巩固
2:new[]，delete[]模拟
3:new,delete / new[],delete[] / malloc(),free()配对使用，
不配对使用可能导致的问题
4:浅拷贝和深拷贝
**********************************************************************/

class Test1
{
public:
	Test1()
	{}
	Test1(int t) :_t(t)
	{
		cout << "this is Test1()" << endl;
		//malloc() ,open
	}
	~Test1()
	{
		cout << "this is ~Test1()" << endl;
		//free() ,close
	}
private:
	int _t;
};

void test()
{
	//错误1：要加默认构造函数，不然下一行报错，why?

	/*遇到问题：
	如下一行内存大小为 44 字节；
	由调试可知：前4个字节存储该数组大小 10；
	结论：delete时调用析构函数，必须给出调用析构函数的个数

	如果函数没有写析构函数,则为 40 字节，因为不会显示调用析构函数
	*/
	Test1* t1 = new Test1[10];  //new(t1)Test1(10);  //顺带初始化

	/*  new,new[]操作符不能重载，包含 先后 两部分：
	1 operator new ：分配空间，内部调用malloc()
	2 调用构造函数：new定位表达式 -》显示调用

	delete,delete[]:先后两部分
	1 调用析构函数
	2 释放空间：内部调用 free()
	*/

	Test1* array1 = new Test1[10];
	delete[] array1;
	//new[]模拟
	//分配空间
	Test1* array2 = (Test1 *)malloc(sizeof(Test1)* 10 + 4);
	//首先，让前4个字节(int )存储数组长度
	*((int *)array2) = 10;
	//指向有效空间对空间初始化
	array2 = (Test1 *)((int *)array2 + 1);
	//调用构造函数
	for (int i = 0; i < 10; ++i)
	{
		//new 定位表达式
		new(array2 + i)Test1(1);
	}

	//模拟delete[]
	//把数组长度付给count
	int count = *((int *)array2 - 1);
	for (int i = 0; i < count; ++i)
	{
		array2[i].~Test1();
	}
	//指针复原； 不复原崩溃；
	array2 = (Test1 *)((int *)array2 - 1);
	//array2 = (Test1 *)((int)array2 + 4);
	operator delete(array2);


	/*
	操作符不匹配造成的问题
	*/
	//int* p1 = new int;
	//free(p1);   //基本类型，无析构，不会崩溃
	//delete p1;

	//int* p2 = new int[10];
	//free(p2);   //基本类型，无析构，不会崩溃

	//Test1* p3 = new Test1;
	//free(p3);     //有析构，不会崩溃，但如果析构（有free），崩溃?

	//Test1* p4 = new Test1[10];
	//delete p4;    //调用一次析构函数，崩溃
	//free(p4);     //没有调析构函数，崩溃
}