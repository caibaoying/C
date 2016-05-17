#include <stdio.h>
void print()           //打印9*9乘法口诀表
{
	for(int i=1; i<=9; i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%d*%d=%2d   ",j,i,i*j);
		}
		printf("\n");
	}
}