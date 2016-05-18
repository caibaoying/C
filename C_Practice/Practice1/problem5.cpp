#include <stdio.h>
int Max_arr()            //数组的最大数
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
    int max = arr[0];
	for(int i=1; i<10; i++)
	{
		if(max<arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}