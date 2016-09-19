//#include <iostream>
//#include <Windows.h>
//#include <map>
//
//using namespace std;
//
//map<int, int> myMap;
//
//bool dealMin(int n, int min)
//{
//	int array[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	int array2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	
//	while (n > 10)
//	{
//		int bit = n%10;
//		int bit2 = min % 10;
//		array[bit]++;
//		array2[bit2]++;
//		n /= 10;
//		min /= 10;
//	}
//
//	for (int i = 0; i < 10; ++i)
//	{
//		if (array[i] != array2[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0, m = 0;
//	for (int i = 0; i < 2; ++i)
//	{
//		scanf("%d", &n);
//		scanf("%d", &m);
//		myMap.insert(pair<int,int>(n,m));
//	}
//	map<int,int>::iterator iter = myMap.begin();
//	while (iter != myMap.end())
//	{
//		int normal = iter->first;
//		int min = iter->second;
//		bool ret = dealMin(normal, min);
//		if (ret)
//		{
//			printf("YES\n");
//		}
//		else
//			printf("NO\n");
//		++iter;
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <stack>
//using namespace std;
//struct info
//{
//	int row;
//	int col;
//	int value;
//	info(int _row, int _col, int _value)
//		:row(_row)
//		, col(_col)
//		, value(_value)
//	{}
//};
//
//int main()
//{
//	int t = 0;
//	int n = 0, m = 0;
//
//	scanf("%d", &t);
//	for (int i = 0; i < t; ++i)
//	{
//		scanf("%d%d", &n, &m);
//	}
//	int ** array = new int*[m];
//	char a[100];
//	for (int i = 0; i < n; ++i)
//	{	
//		scanf("%s", a);
//		for (int index = 0; a[index] != '\0'; ++index)
//		{
//			array[i][index] = a[i] - '0';
//		}
//	}
//
//	stack<info> s;
//	
//	for (int i = 0; i < t; ++i)
//	{
//		int size = 0;
//		for(int i = 0; i < n; ++i)
//		{
//			for (int j = 0; j < m; ++j)
//			{
//				if (array[i][j - 1] && array[i][j - 1] == 1)
//				{
//					int up = array[i][j - 1];
//					info node(i, j - 1, up);
//					s.push(node);
//				}
//
//				if (array[i][j + 1] && array[i][j + 1] == 1)
//				{
//					int down = array[i][j + 1];
//					info node(i, j + 1, down);
//					s.push(node);
//				}
//
//				if (array[i - 1][j] && array[i - 1][j] == 1)
//				{
//					int left = array[i - 1][j];
//					info node(i - 1, j, left);
//					s.push(node);
//				}
//
//				if (array[i + 1][j] && array[i + 1][j] == 1)
//				{
//					int right = array[i + 1][j];
//					info node(i + 1, j, right);
//					s.push(node);
//				}
//
//				while (!s.empty())
//				{
//					info top = s.top();
//					int row = top.row;
//					int col = top.col;
//					s.pop();
//					if (!s.empty() && row == i && col == j)
//						++size;
//				}
//			}
//		}
//		printf("%d", size);
//	}
//
//	return 0;
//}

#include <iostream>
#include <Windows.h>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A() ";
	}

	~A()
	{
		cout << "~A() ";
	}
private:
	int a;
};

class B
{
public:
	B(int b)
	{
		cout << "B() ";
	}

	~B()
	{
		cout << "~B() ";
	}
};

class C
{
public:
	C(int c)
	{
		cout << "C() ";
	}

	~C()
	{
		cout << "~C() ";
	}
//private:
	int c;
};

class D:public C
{
public:
	D(int a, int b, int c)
		:a(a)
		, b(b)
		, C(c)
	{
		cout << "D() ";
	}

	~D()
	{
		cout << "~D() ";
	}

private:
	B b;
	A a;
};

void test1()
{
	int a;
	char c = 10;
	float f = 100.0;
	double x;
	a = f /= c *= (x = 6.5);
	printf("%d %d %3.1lf %3.1lf\n", a,c,f,x);
}

void test2()
{
	char *a[3] = { "I", "love", "tomat" };
	char ** ptr = a;
	printf("%c %s ", *(*(a + 1) + 1), *(ptr + 1));
	printf("%d %d ", sizeof(**a), sizeof(ptr));
}

int main()
{
	//C* p = new D(1,2,3);
	//delete p;

	//int a[2][3] = {1,2,3,4,5,6};
	//cout << *(*(a+1));

	//test1();
	test2();
	system("pause");
	return 0;
}