//CVTE笔试题，选出最新时间戳
#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
int Timer(char** timer, int length)
{
	if (NULL == timer || length <= 0)
	{
		return -1;
	}

	char* prev = NULL;
	char* cur = NULL;
	int i = 1;
	prev = timer[i - 1];
	int index = 0;
	for (i = 1; i < length; ++i)
	{
		cur = timer[i];
		if (strcmp(prev, cur) > 0)
		{
			prev = cur;
			index = i;
		}
	}

	return index;
}

void Test()
{
	char *p[3] = { { "20160902_030405" }, { "20160902_040506" }, { "20160907_010203" } };
	int length = 3;
	cout << Timer(p, 3)<<endl;
}

//大数运算加法

char* add(char* a, char* b)
{
	if (NULL == a || NULL == b)
	{
		return NULL;
	}

	int length1 = 0, length2 = 0;

	for (int i = 0; a[i] != '\0'; ++i)
	{
		length1++;
	}

	for (int j = 0; b[j] != '\0'; ++j)
	{
		length2++;
	}

	int MinLength = length1 < length2 ? length1 : length2;
	int MaxLength = length1 > length2 ? length1 : length2;
	int MulLength = abs(length1 - length2);

	char* result = new char[MaxLength+1];
	int flag = 0;
	int index = 0;
	for (index = MaxLength-1; index >= 0; --index)
	{
		int add = a[index]+b[index-MulLength]+flag -'0';
		if (a[index] && b[index - MulLength] && add >= 10)
		{
			flag = 1;
			result[index + 1] = add + '0';
		}
		else if (a[index] && b[index] && add < 10)
		{
			flag = 0;
			result[index + 1] = add + '0';
		}
		else
			break;
	}

	if (length1 >= length2)
	{
		for (int i = index; i >= 0; --i)
		{
			int add = a[i] + flag - '0';
			if (add > 10)
			{
				flag = 1;
			}
			else
				flag = 0;

			result[i + 1] = add + '0';
		}
		if (flag)
		{
			result[0] = flag + '0';
		}
	}
	else
	{
		for (int i = index; i >= 0; --i)
		{
			int add = b[i] + flag - '0';
			if (add > 10)
			{
				flag = 1;
			}
			else
				flag = 0;

			result[i + 1] = add + '0';
		}
		if (flag)
		{
			result[0] = flag + '0';
		}
	}

	return result;
}

void Test1()
{
	char* a = "111111111111119";
	char* b = "99999999991";
	cout << add(a, b) << endl;
}