#pragma once 
#include <assert.h>

// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一行都按照从上到下的递增的顺序排序。请完成一个
// 一个函数，输入一个数，查找在不在

bool Find(int matrix[][4], int row, int col, int num)   //num为要查找的数
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