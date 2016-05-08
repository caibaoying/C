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

////���̳ж���ģ��
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
////�ú���ָ�������ú������궨��ʵ��
//typedef void(*FUNC) ();
//
//void PrintVTable(int* VTable)
//{
//	cout << " ����ַ>" << VTable << endl;
//	//vc����0���жϽ���
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, VTable[i]);
//		FUNC f = (FUNC)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//void Test1()
//{
//	Base b1;     //����
//	Derive d1;   //���࣬���������ʵ�����麯����д���������д������Ĭ�ϻ���
//	//���Դ�����û����ʾfun3()&fun4() ,ΪVC��bug
//	int* VTable1 = (int*)(*(int*)&b1);   //Ҫ��ӡ����ȵ�ǿת�������ã���ǿת���õ���ַ
//	int* VTable2 = (int*)(*(int*)&d1);
//	PrintVTable(VTable1);              //���ô�ӡ������ӡ
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
	cout << " ����ַ>" << VTable << endl;
	for (int i = 0; VTable[i] != 0; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, VTable[i]);
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
	// Base2�麯�����ڶ���Base1����
	VTable = (int *)(*((int*)&d1 + sizeof (Base1) / 4));
	PrintVTable(VTable);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}