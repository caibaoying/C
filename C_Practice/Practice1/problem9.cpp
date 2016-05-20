#include <stdio.h>
void Exchange(int *one,int *other)          //交换两个整数的值
{
	int *temp;
	temp = one;
	one = other;
	other = temp;
    printf("%d   %d \n",*one,*other);
}