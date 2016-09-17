//#include <iostream>
//#include <Windows.h>
//#include <map>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	map<int, int> myMap;
//	for (int i = 0; i < 3; ++i)
//	{
//		scanf("%d%d", &m, &n);
//		myMap.insert(pair<int, int>(m, n));
//	}
//	map<int, int>::iterator iter = myMap.begin();
//	while (iter != myMap.end())
//	{
//		double total = 0.0;
//		double tmp = iter->first;
//		for (int i = 0; i < iter->second; ++i)
//		{
//			total += tmp;
//			tmp = sqrt(tmp);
//		}
//		printf("%.2lf\n", total);
//		++iter;
//	}
//
//	system("pause");
//	return 0;
//}