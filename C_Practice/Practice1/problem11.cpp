#include <stdio.h>
#define Year 2000
void leap_year()           //���2000��֮ǰ������͸���
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