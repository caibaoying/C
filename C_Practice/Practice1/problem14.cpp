#include <stdio.h>
#define High 100.0
void Height()             //С�򷴵��߶�
{
    double H = High,total = 0.0;
	for(int i=1; i<=10; i++)
	{
		total = total+H;
		H = H/2;
	}
	printf("%lf %lf \n",total,H);
}