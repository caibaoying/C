//#include <iostream>
//#include <math.h>
//#include <map>
//#include <Windows.h>
//using namespace std;
//
//int main()
//{
//	map<int, int> mymap;
//	int m, n;
//	for (int i = 0; i < 3; ++i)
//	{
//		scanf("%d%d", &m, &n);
//		mymap.insert(pair<int, int>(m, n));
//	}
//
//	map<int, int>::iterator iter = mymap.begin();
//	while (iter != mymap.end())
//	{
//		int flag = 0;
//		for (int i = iter->first; i <= iter->second; ++i)
//		{
//			int tmp = i;
//			int low = tmp % 10;
//			int mid = tmp / 10 % 10;
//			int high = tmp / 100;
//			int total = pow(low, 3) + pow(mid, 3) + pow(high, 3);
//
//			if (total == i)
//			{
//				flag = 1;
//				printf("%d ", i);
//			}
//		}
//		if (!flag)
//			printf("no");
//		++iter;
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}