#include <stdio.h>
#define A 105
#define B 255
int gcd(int Chu_shu,int Yu_shu)
{
    if(Yu_shu == 0)
	{
		return Chu_shu;
	}
	gcd(Yu_shu,Chu_shu%Yu_shu);
}
int Gy_max()              //求两个数的最大公约数
{
    int a = A,b = B;
	int Chu_shu = b;
	int Yu_shu = a%b;
	return gcd(Chu_shu,Yu_shu);
}