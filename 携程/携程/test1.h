//#include <iostream>
//#include <Windows.h>
//
//using namespace std;
//
//int main()
//{
//	/*char array[100] = {0};
//	scanf("%s", array);
//	int buy = 0, sale = 0;
//	int max = (array[2]-'0')-(array[0]-'0');
//	for (int i = 4; array[i] != '\0'; ++i)
//	{
//		buy = array[i] - '0';
//		if (array[i + 2])
//		{
//			sale = array[i + 2] - '0';
//		}
//		else
//		{
//			break;
//		}
//		if (array[i] != ',')
//		{
//			int tmp = sale - buy;
//			max = (max < tmp ? tmp : max);
//		}
//	}
//	printf("%d\n", max);
//	system("pause");
//	return 0;*/
//}

//#include <iostream>
//#include <stdio.h>
//#include <Windows.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int find(int num, int * array, int begin, int end,bool flag)
//{
//	if (NULL == array)
//	{
//		printf("(-1)--1\n");
//		return -1;
//	}
//	if (begin == end)
//	{
//		if (flag)
//			printf("(-1)-%d\n", begin-1);
//		else
//			printf("(-1)-%d\n", end + 1);
//		return -1;
//	}
//	int left = array[begin];
//	int right = array[end];
//	int mid = end- (end - begin) / 2;
//	if (num == array[mid])
//	{
//		printf("%d\n", mid);
//		return 1;
//	}
//	if (num > array[mid])
//	{
//		find(num, array, mid+1, end, true);
//	}
//	if (num < array[mid])
//	{
//		find(num, array, begin, mid-1, false);
//	}
//}
//
//int main()
//{
//	int findNum;
//	int arrayNum;
//	scanf("%d", &findNum);
//	scanf("%d", &arrayNum);
//
//	int* myVec = new int[arrayNum];
//	int n;
//	for (int i = 0; i < arrayNum; ++i)
//	{
//		scanf("%d", &n);
//		myVec[i] = n;
//	}
//	//sort(myVec, myVec+arrayNum-1);
//
//	find(findNum, myVec, 0, arrayNum-1, true);
//	system("pause");
//	return 0;
//}