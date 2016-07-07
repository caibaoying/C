#include <iostream>
#include <Windows.h>
#include <assert.h>

using namespace std;

// 1、统计一个数二进制中1的个数
int Count_one_number(int num)
{
	int count = 0;
	while (num)
	{
		if (num & 1 == 1)
		{
			count++;
		}
		num >>= 1;
	}
	return count;
}

void Test_Count_one_number()
{
	int a = 10;
	printf("1、统计一个数二进制中1的个数：%d\n", Count_one_number(a));
}

// 2、两个int（32位）整数m和n的二进制表达式中，有多少个位不同
int Two_num_diff(int m, int n)
{
	int tmp = m^n;
	return Count_one_number(tmp);
}

void Test_Two_num_diff()
{
	int m = 10;
	int n = 15;
	printf("2、%d和%d的二进制表达式中，有 %d 个位不同\n", m, n, Two_num_diff(m, n));
}

// 3、判断一个数是不是2的n次方
bool Judge_num(int m)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (m & 1 == 1)
			count++;
		m >>= 1;
	}
	if (count == 1)
		return true;
	else
		return false;
}

void Test_Judge_num()
{
	int a = 8;
	printf("3、判断%d是不是2的n次方：%d\n", a, Judge_num(a));
}

// 4、写一个宏定义，实现的功能是将一个int型的数的奇偶位互换；eg:0110-->1001,输出应该为9
#define Exchage(x) (((x & 0x55555555)<<1)|((x & 0xaaaaaaaa)>>1))
void Test_Exchange()
{
	int a = 6;
	printf("4、将一个int型的数 %d 的奇偶位互换 --> %d\n", a, Exchage(a));
}

// 5、将一个二进制序列逆序，然后输出逆序之后的二进制所对应的数
int Reverse_num(int m)
{
	int tmp = 0;
	int num = m;
	for (int i = 0; i < 32; ++i)
	{
		tmp <<= 1;
		if ((num & 1) == 1)
		{
			tmp = tmp | 1;
		}

		num >>= 1;
	}
	return tmp;
}

void Test_Reverse_num()
{
	int a = 10;
	printf("5、将一个二进制序列 (0 1010) 逆序:%d\n", Reverse_num(a));
}

// 6、编写一个函数，这个函数可以将一个整数的指定位置置1或者0
void Set_num(int *num, int pos, int flag)
{
	if (pos > 32 || pos <= -1)
		return;
	if (flag == 1)
		(*num) |= (1 << (pos - 1));
	else
		(*num) &= (~(1 << (pos - 1)));
}

void Test_Set_num()
{
	int num = 10;
	int pos = 3;
	int flag = 1;
	printf("6、将%d的第%d位置成%d", num, pos, flag);
	Set_num(&num, pos, flag);
	printf(" -->%d\n", num);
}

// 7、给一组数，只有一个数只出现了一次，其他所有数都成对出现，找出这个数
int Find_num1(int* array, int size)
{
	assert(array);
	int num = array[0];
	for (int i = 1; i < size; ++i)
	{
		num ^= array[i];
	}
	return num;
}

void Test_Find_num1()
{
	int array[] = { 1, 2, 3, 4, 1, 2, 3, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	int num = Find_num1(array, size);
	printf("7、一个数只出现了一次，其他所有数都成对出现:%d\n", num);
}

// 8、给一组数，只有两个数只出现了一次，其他所有数据都是成对出现的。找出这两个数
void Find_num2(int* array, int size, int* first, int* second)
{
	assert(array);
	int num = array[0];
	int pos = 0;
	for (int i = 1; i < size; ++i)
	{
		num ^= array[i];
	}

	int tmp = num;
	for (int i = 0; i < 32; ++i)
	{
		if (tmp & 1 == 1)
			break;
		++pos;
		tmp >>= 1;
	}

	for (int i = 0; i < size; ++i)
	{
		if (((array[i] >> pos) & 1) == 1)
		{
			*first ^= array[i];
		}
	}

	*second = num ^ (*first);
	printf("8、两个数只出现了一次，其他所有数据都是成对出现的: %d,%d\n", *first, *second);
}

void Test_Find_num2()
{
	int array[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int first = 0, second = 0;
	int size = sizeof(array) / sizeof(int);
	Find_num2(array, size, &first, &second);
}
int main()
{
	Test_Count_one_number();
	Test_Two_num_diff();
	Test_Judge_num();
	Test_Exchange();
	Test_Reverse_num();
	Test_Set_num();
	Test_Find_num1();
	Test_Find_num2();
	system("pause");
	return 0;
}