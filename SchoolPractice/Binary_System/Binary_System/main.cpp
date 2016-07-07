#include <iostream>
#include <Windows.h>
#include <assert.h>

using namespace std;

// 1��ͳ��һ������������1�ĸ���
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
	printf("1��ͳ��һ������������1�ĸ�����%d\n", Count_one_number(a));
}

// 2������int��32λ������m��n�Ķ����Ʊ��ʽ�У��ж��ٸ�λ��ͬ
int Two_num_diff(int m, int n)
{
	int tmp = m^n;
	return Count_one_number(tmp);
}

void Test_Two_num_diff()
{
	int m = 10;
	int n = 15;
	printf("2��%d��%d�Ķ����Ʊ��ʽ�У��� %d ��λ��ͬ\n", m, n, Two_num_diff(m, n));
}

// 3���ж�һ�����ǲ���2��n�η�
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
	printf("3���ж�%d�ǲ���2��n�η���%d\n", a, Judge_num(a));
}

// 4��дһ���궨�壬ʵ�ֵĹ����ǽ�һ��int�͵�������żλ������eg:0110-->1001,���Ӧ��Ϊ9
#define Exchage(x) (((x & 0x55555555)<<1)|((x & 0xaaaaaaaa)>>1))
void Test_Exchange()
{
	int a = 6;
	printf("4����һ��int�͵��� %d ����żλ���� --> %d\n", a, Exchage(a));
}

// 5����һ����������������Ȼ���������֮��Ķ���������Ӧ����
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
	printf("5����һ������������ (0 1010) ����:%d\n", Reverse_num(a));
}

// 6����дһ������������������Խ�һ��������ָ��λ����1����0
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
	printf("6����%d�ĵ�%dλ�ó�%d", num, pos, flag);
	Set_num(&num, pos, flag);
	printf(" -->%d\n", num);
}

// 7����һ������ֻ��һ����ֻ������һ�Σ��������������ɶԳ��֣��ҳ������
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
	printf("7��һ����ֻ������һ�Σ��������������ɶԳ���:%d\n", num);
}

// 8����һ������ֻ��������ֻ������һ�Σ������������ݶ��ǳɶԳ��ֵġ��ҳ���������
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
	printf("8��������ֻ������һ�Σ������������ݶ��ǳɶԳ��ֵ�: %d,%d\n", *first, *second);
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