#include <stdio.h>
double Add()         //数列的20项之和
{
	double f1 = 2.0,f2 = 1.0,f3,total = 0.0;
	for(int i=1; i<=20; i++)
	{
		total = total+f1/f2;
		f3 = f1;
		f1 = f1+f2;
		f2 = f3;	
	}
	return total;	
}