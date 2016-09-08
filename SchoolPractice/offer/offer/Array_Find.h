#pragma once 
#include <assert.h>

// ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µĵ�����˳�����������һ��
// һ������������һ�����������ڲ���

bool Find(int matrix[][4], int row, int col, int num)   //numΪҪ���ҵ���
{
	assert(matrix);
	int flag = false;
	int core = matrix[0][col-1];
	int _row = 0;
	int _col = col-1;
	while (core != num && _col > 0 && _row < row)
	{
		if (core > num)
		{
			--_col;
			core = matrix[_row][_col];
		}
		else if (core < num)
		{
			++_row;
			core = matrix[_row][_col];
		}
	}
	if (core == num)
	{
		cout << "row:" << _row << " col:" << _col << endl;
		flag = true;
	}
	return flag;
}

void Test_Find()
{
	int matrix[4][4]= {
		{1,2,4,8},
		{2,4,6,9},
		{3,6,8,10},
		{4,8,10,11}
	};
	cout << Find(matrix, 4, 4, 11) << endl;
}