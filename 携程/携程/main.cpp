#include <iostream>
#include <Windows.h>
#include <stack>
using namespace std;

struct info
{
	int _row;
	int _col;
	int _value;
	info(int row, int col, int value)
		:_row(row)
		, _col(col)
		, _value(value)
	{}
};

stack<info> s;

void push(int array[][5], int row, int col)
{
	int up = -1;
	int down = -1;
	int left = -1;
	int right = -1;
	int cur = array[row][col];


	if (array[row][col - 1])
	{
		up = array[row][col - 1];
		info node(row, col - 1, up);
		s.push(node);
	}

	if (array[row][col + 1])
	{
		down = array[row][col + 1];
		info node(row, col + 1, down);
		s.push(node);
	}

	if (array[row - 1][col])
	{
		left = array[row - 1][col];
		info node(row - 1, col, left);
		s.push(node);
	}

	if (array[row + 1][col])
	{
		right = array[row + 1][col];
		info node(row + 1, col, right);
		s.push(node);
	}
}

void set(int array[][5], int row, int col)
{
	while (!s.empty())
	{
		info top = s.top();
		s.pop();
		if (top._value == 1 && top._col != col && top._row != row)
		{
			array[top._row][top._col] = 0;
			push(array, top._row, top._col);
		}
	}
}

int main()
{
	int flag = 0;

	int array[][5] = { 
	{ 1, 1, 0, 0, 1 }, 
	{ 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 1 } };

	for (int row = 0; row < 5; ++row)
	{
		for (int col = 0; col < 5; ++col)
		{
			//push(array, row, col);
			int up = -1;
			int down = -1;
			int left = -1;
			int right = -1;
			int cur = array[row][col];

			if (array[row -1][col] && row >= 1)
			{
				up = array[row-1][col];
				info node(row-1, col, up);
				s.push(node);
			}

			if (array[row+1][col])
			{
				down = array[row+1][col];
				info node(row+1, col, down);
				s.push(node);
			}

			if (array[row][col-1] && col >= 1)
			{
				left = array[row][col-1];
				info node(row, col-1, left);
				s.push(node);
			}

			if (array[row][col+1])
			{
				right = array[row][col+1];
				info node(row, col+1, right);
				s.push(node);
			}

			//set(array, row, col);
			while (!s.empty())
			{
				info top = s.top();
				s.pop();
				if (top._value == 1 && (top._col != col || top._row != row))
				{
					array[top._row][top._col] = 0;
					push(array, top._row, top._col);
				}
			}

			for (int col2 = 0; col2 < 5; ++col2)
			{
				if (array[row][col2] == 1)
				{
					++flag;
				}
			}
		}
	}

	for (int row = 0; row < 5; ++row)
	{
		
	}
	printf("%d\n", flag);
	system("pause");
	return 0;
}

