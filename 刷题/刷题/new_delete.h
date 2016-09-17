#pragma once

#include <iostream>
using namespace std;
/*********************************************************************
1:new,new[],delete,delete[]����
2:new[]��delete[]ģ��
3:new,delete / new[],delete[] / malloc(),free()���ʹ�ã�
�����ʹ�ÿ��ܵ��µ�����
4:ǳ���������
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
	//����1��Ҫ��Ĭ�Ϲ��캯������Ȼ��һ�б���why?

	/*�������⣺
	����һ���ڴ��СΪ 44 �ֽڣ�
	�ɵ��Կ�֪��ǰ4���ֽڴ洢�������С 10��
	���ۣ�deleteʱ����������������������������������ĸ���

	�������û��д��������,��Ϊ 40 �ֽڣ���Ϊ������ʾ������������
	*/
	Test1* t1 = new Test1[10];  //new(t1)Test1(10);  //˳����ʼ��

	/*  new,new[]�������������أ����� �Ⱥ� �����֣�
	1 operator new ������ռ䣬�ڲ�����malloc()
	2 ���ù��캯����new��λ���ʽ -����ʾ����

	delete,delete[]:�Ⱥ�������
	1 ������������
	2 �ͷſռ䣺�ڲ����� free()
	*/

	Test1* array1 = new Test1[10];
	delete[] array1;
	//new[]ģ��
	//����ռ�
	Test1* array2 = (Test1 *)malloc(sizeof(Test1)* 10 + 4);
	//���ȣ���ǰ4���ֽ�(int )�洢���鳤��
	*((int *)array2) = 10;
	//ָ����Ч�ռ�Կռ��ʼ��
	array2 = (Test1 *)((int *)array2 + 1);
	//���ù��캯��
	for (int i = 0; i < 10; ++i)
	{
		//new ��λ���ʽ
		new(array2 + i)Test1(1);
	}

	//ģ��delete[]
	//�����鳤�ȸ���count
	int count = *((int *)array2 - 1);
	for (int i = 0; i < count; ++i)
	{
		array2[i].~Test1();
	}
	//ָ�븴ԭ�� ����ԭ������
	array2 = (Test1 *)((int *)array2 - 1);
	//array2 = (Test1 *)((int)array2 + 4);
	operator delete(array2);


	/*
	��������ƥ����ɵ�����
	*/
	//int* p1 = new int;
	//free(p1);   //�������ͣ����������������
	//delete p1;

	//int* p2 = new int[10];
	//free(p2);   //�������ͣ����������������

	//Test1* p3 = new Test1;
	//free(p3);     //������������������������������free��������?

	//Test1* p4 = new Test1[10];
	//delete p4;    //����һ����������������
	//free(p4);     //û�е���������������
}