#include <stdio.h>
#include <math.h>
#define T 100
void Su_shu()   //��1-100�������
{
	for(int j=1; j<=T; j++)
	{
		bool flag = true;
        for(int i=2; i<=sqrt(j); i++)
		{
			if(j%i == 0)
			{
		        flag = false;
			}
		}
		if(flag)
		{
			printf("%d ",j);
		}
	}	
}