#include <stdio.h>
#include <math.h>

int Add1()          //S = a+aa+aaa+aaa------aaaaaaa
{
	int sum = 0,a,n,S = 0;
	scanf("%d%d",&a,&n);
    for(int i=1; i<=n; i++)
	{
		sum = sum+a*pow(10,i-1);
		S = S+sum;
	}
    return S;
}