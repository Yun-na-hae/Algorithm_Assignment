#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;


void quickSort(int* arr, int left , int right)
{
	if(left<right){
		int i = left,
			j = right + 1,
			pivot = arr[left];
		do{
			do i++; while(arr[i]<pivot);
			do j--; while(arr[j]>pivot);
			if(i<j) swap(arr[i],arr[j]);
		}while(i<j);
			swap(arr[left],arr[j]);

			quickSort(arr,left,j-1);
			quickSort(arr,j+1,right);
	}
}


int main()
{

	int *arr;
	int num;

	cout<<"배열의 크기를 입력하시오 : ";cin>>num;
	arr = new int[num];

	long start,stop;
	long init_start,init_stop;

	time(&start);

	for(int j = 0;j<30000;j++) {
		for(int i  = 0; i < num ; i++)
			arr[i] = num - i-1;

		quickSort(arr,0,num-1);

	}
	time(&stop);

	time(&init_start);
	for(int j = 0;j<30000;j++) {
		for(int i = 0;i<num;i++)
			arr[i] = num - i -1;
	}
	time(&init_stop);

	cout<<"Time : "<<(stop - start) - (init_stop - init_start)<<endl;

	return 0;
}
