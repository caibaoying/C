#include <stdio.h>

int add();                 //��1-100����100�������ĺ�
void print();              //��ӡ9*9�˷��ھ���
int Max();                 //���������Ľϴ�ֵ
int Max_arr();             //����������
void Su_shu();             //��1-100�������
int Gy_max();              //�������������Լ��
int Gb_min();              //������������С������
void Exchange(int *one,int *other);          //��������������ֵ
void San_ws();             //����λ��
void leap_year();          //���2000��֮ǰ������͸���
double Add();              //���е�20��֮��
int Add1();                //S = a+aa+aaa+aaa------aaaaaaa
void Height();             //С�򷴵��߶�
void Monkey();             //���ӳ���
double Add2();             //1-1/2+1/3----
int Add3();                //N�Ľ׳����

void main()
{
	//1 ���hello world/////////////////////// 
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
	printf("��ͣ�%lf \n",Add2());
	//17
	printf("�׳ˣ�%d\n",Add3());
}