#include <iostream>
#include <math.h>
#include <assert.h>
#include "timer.h"
#include <Windows.h>
//
using namespace std;
//
//int* input(const int& n,const  int& m)
//{
//	int priceNum[n];
//	char* dietNum[m];
//	for (int i = 0; i < n; ++i)
//	{
//		cout << priceNum[i] << " ";
//	}
//	cout << endl;
//	for (int j = 0; j < m; ++j)
//	{
//		cout << *dietNum + j << endl;
//	}
//
//	return priceNum;
//}
//
//void output(int* tmp, int n, int m)
//{
//	assert(tmp);
//	sort(tmp,n);
//	if (n < m)    // 确保有所有物品
//	{
//		return;
//	}
//
//	int MaxCost = 0;
//	int MinCost = 0;
//
//	for (int i = 0; i < n; ++i)
//	{
//		if (i < m)
//		{
//			MinCost += i;
//		}
//
//		if (i >= n - m)
//		{
//			MaxCost += i;
//		}
//	}
//
//	cout << MinCost << MaxCost << endl;
//}
//
//int main()
//{
//	int n = 0, m = 0;   //n价签数， m 为物品单数
//	scanf("%d%d\n", &n, &m);
//	int* tmp = input(n, m);
//	output(tmp, n, m);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	int Circle[n];
//	cin >> n;
//	cout << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> Circle[i] << " ";
//	}
//	cout < endl;
//
//	int array[n];  // 并查集解决该问题
//	
//
//
//	return 0;
//}

int main()
{
	//Test1();
	int p[2][3] = { { 1, 2, 5 }, { 3, 4, 6 } };
	cout << sizeof(p)<<sizeof(*p)<<sizeof(**p) << endl;
	cout << *(*p+1) << endl;
	cout << *p + 1 << endl;
	system("pause");
	return 0;
}