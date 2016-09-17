//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <Windows.h>
//using namespace std;
//
//bool judge(int num)
//{
//	if (num <= 2)
//		return false;
//	for (int i = 2; i <= sqrt(num); ++i)
//	{
//		if (num % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	vector<int> myvector;
//	int m = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d", &m);
//		myvector.push_back(m);
//	}
//	
//	vector<int> NumVector; // 存储相邻两个数间的质数个数
//	vector<int>::iterator Myiter = myvector.begin();
//	while (Myiter != myvector.end()-1)
//	{
//		int result = 0;
//		for (int i = *Myiter; i <= *(Myiter+1); ++i)
//		{
//			if (judge(i))
//			{
//				++result;
//			}
//		}
//		NumVector.push_back(result);
//		++Myiter;
//	}
//
//	int total = 0;
//	int sum = NumVector.size();
//	cout << sum << endl;
//	for (int i = 0; i < NumVector.size(); ++i)
//	{
//		cout << NumVector[i] << endl;
//		total += sum*NumVector[i];
//		sum--;
//	}
//	cout << total;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <memory>
#include <Windows.h>
#include <vector>
using namespace std;

int judge(char* buf)
{
	if (NULL == buf)
	{
		return -1;
	}
	int result = 0;
	
	for (int i = 1; buf[i] != '\0'; ++i)
	{
		int tmp1 = i - 1;
		int tmp2 = i + 1;
		int tmp = i;
		int total1 = 0;
		int total2 = 0;
		while (buf[tmp1] && buf[tmp2] && buf[tmp1] == buf[tmp2])
		{
			total1 += 2;
			--tmp1;
			++tmp2;
		}
		while (buf[tmp1] && buf[tmp] && buf[tmp1] == buf[tmp])
		{
			total2 += 2;
			++tmp;
			--tmp1;
		}
		if (total1 < total2 && result < total2)
		{
			result = total2;
		}	
		else if (total2 < total1 && result < total1)
		{
			result = total1 + 1;
		}
	}
	return result;
}

int main()
{
	/*FILE* file = fopen("a.txt", "w");
	char buf[1024];
	memset(buf, sizeof(buf), '\0');
	scanf("%s", buf);
	fputs(buf, file);
	cout<<judge(buf);*/
	//printf("11"+"22");
	vector<pair<int, int>> a;
	a.push_back(pair<int,int>(3,5));
	a.push_back(pair<int, int>(1, 8));
	a.push_back(pair<int, int>(2, 6));
	for (int i = 0; i < a.size(); ++i)
	{
		printf("%d ", pair<int, int>(3, 5));
	}


	system("pause");
	return 0;
}