#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

void ascendingSort(int *arr, int num)
{
	int temp=0;

	for(int j=0;j<num;j++)
	{
		for(int i=0;i<num-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
}


int binarySearch(int num,int *arr,int key)
{
	int low,high,mid;
	int location = num;

	low = 0; high = num-1;

	while(low <= high && location == num)
	{
		mid = (low+high)/2;

		if(key==arr[mid])
			location = mid;
		else if(key<arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return location;
}


int main()
{
	int num;
	int* arr;
	int key;
	int location;

	cout<<"배열의 크기를 입력하시오 : ";cin>>num;
	arr = new int[num];

	long start,stop;
	long init_start,init_stop;

	time(&start);
	for(int j = 0;j<300000;j++) {

		for(int i = 0;i<num;i++)
			arr[i] = i;

		key = num;

		ascendingSort(arr,num);	

		location = binarySearch(num,arr,key);
	}
	time(&stop);

	time(&init_start);
	for(int j = 0;j<300000;j++)
		for(int i = 0;i<num;i++)
			arr[i] = i;
	time(&init_stop);

	cout<<"Time : "<<(stop-start)-(init_stop-init_start)<<endl;

	return 0;
}
