#include <stdio.h>
void Exchange(int *one,int *other)          //��������������ֵ
{
	int *temp;
	temp = one;
	one = other;
	other = temp;
    printf("%d   %d \n",*one,*other);
}