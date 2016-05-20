#include <stdio.h>
#define A 105
#define B 255
int gcd1(int Chu_shu,int Yu_shu)
{
    if(Yu_shu == 0)
	{
		return Chu_shu;
	}
	gcd1(Yu_shu,Chu_shu%Yu_shu);
}
int Gb_min()              //求两个数的最小公倍数
{
    int a = A,b = B;
	int Chu_shu = b;
	int Yu_shu = a%b;
	return a*b/gcd1(Chu_shu,Yu_shu);
}