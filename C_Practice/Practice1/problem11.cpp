#include <stdio.h>
#define Year 2000
void leap_year()           //输出2000年之前的闰年和个数
{
	int sum = 0;
	for(int i=1; i<Year; i++)
	{
		if((i%4==0 && i%100!=0) || i%400==0)
		{
			printf("%5d",i);
			sum++;
		}
	}
	printf("\n %d \n",sum);
}