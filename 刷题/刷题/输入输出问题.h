#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input()
{
	int N = 0;
	cin >> N;
	vector<char*> array;
	array.resize(0);
	
	for (int i = 0; i < N; ++i)
	{
		char arr[100];
		scanf("%s", arr);
		printf("%s\n", arr);
		array.push_back(arr);
	}

	for (int i = 0; i < N; ++i)
	{
		int total1 = 0;
		int total2 = 0;
		char* tmp1 = array[i];
		char* cur1 = tmp1;
		int length = 0;
		while (*cur1 != '\0')
		{
			++length;
			++cur1;
		}
			
		for (int i = length; i >= 0;i-=2)
		{
			int tmp = *cur1 - '0';
			if (tmp >=0 && tmp <= 9)
				total1 += tmp;
			cur1 += 2;
		}

		char* tmp2 = array[i];
		char* cur2 = tmp2;
		for (int i = length; i > 0; i-=2)
		{
			int tmp = *cur2 - '0';
			if (tmp >= 0 && tmp <= 9)
				total2 += *cur2 - '0';
			cur1 += 2;
		}

		int total = total1 > total2 ? total1 : total2;
		cout << total << endl;
	}

	int array1[10] = { 1, 3, 2, 5, 3, 6, 7 };
	int* array2 = {};
	array2 = (int*)malloc(10 * sizeof(int));
	/*for ()
	{
	}*/

	sort(array1, array1+9);
	for (int i = 0; i < 10; ++i)
	{
		cout << array1[i] << " ";
	}
	cout << endl;
}
