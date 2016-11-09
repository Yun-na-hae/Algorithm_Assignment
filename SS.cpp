#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


int sequentialSearch(int num,int *arr,int key)
{
	int location = 0;

	while(location < num && arr[location] != key)
		location++;

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
	long totalTime = 0;


	time(&start);
	for(long b = 1;b <= 3000000; b++){
		for(int i = 0;i<num;i++)
			arr[i] = num-i-1;
		location = sequentialSearch(num,arr,5000);
	}
	time(&stop);
	time(&init_start);
	for(long b = 1;b <= 3000000;b++){
		for(int i = 0;i<num;i++)
			arr[i] = num-i-1;
	}
	time(&init_stop);
	totalTime = (stop - start) - (init_stop - init_start);
	cout<<"Time : "<<totalTime<<endl;

	return 0;
}



