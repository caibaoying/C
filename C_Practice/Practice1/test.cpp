#include <stdio.h>

int add();                 //求1-100，这100个整数的和
void print();              //打印9*9乘法口诀表
int Max();                 //两个整数的较大值
int Max_arr();             //数组的最大数
void Su_shu();             //求1-100间的素数
int Gy_max();              //求两个数的最大公约数
int Gb_min();              //求两个数的最小公倍数
void Exchange(int *one,int *other);          //交换两个整数的值
void San_ws();             //组三位数
void leap_year();          //输出2000年之前的闰年和个数
double Add();              //数列的20项之和
int Add1();                //S = a+aa+aaa+aaa------aaaaaaa
void Height();             //小球反弹高度
void Monkey();             //猴子吃桃
double Add2();             //1-1/2+1/3----
int Add3();                //N的阶乘相加

void main()
{
	//1 输出hello world/////////////////////// 
	char arr[] = "Hello world";
	char arr1[12] = {'H','e','l','l','o',' ','w','o','r','l','d'};
	char arr2[] = {'H','e','l','l','o',' ','w','o','r','l','d','\0'};
	printf("Hello world\n");
	printf("%s\n",arr);
    printf("%s\n",arr1);
    printf("%s\n",arr2);
    /////////////////////////////////////////
	//2;
	printf("%d \n",add());
	//3;
	print(); 
	//4;
	printf("%d \n",Max());
	//5
    printf("%d \n",Max_arr());
    //6
	Su_shu();
	printf("\n");
	//7
	printf("%d \n",Gy_max()); 
	//8
	printf("%d \n",Gb_min());
	//9
    int a = 10,b = 20;
	Exchange(&a,&b);
	//10
	San_ws();
	printf("\n");
	//11
    leap_year();
    //12
	printf("%lf \n",Add());
    //13
	//printf("%d \n",Add1());
    //14
    Height();
	//15
    //printf("%d\n",Monkey());
	//16
	printf("求和：%lf \n",Add2());
	//17
	printf("阶乘：%d\n",Add3());
}