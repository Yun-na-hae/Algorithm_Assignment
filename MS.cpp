#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <ctime>

using namespace std;

int listMerge(int* arr,int* link,int start1,int start2)
{
	int iResult = 0;
	int i1,i2;

	for(i1 = start1,i2 = start2;i1 && i2; )
		if(arr[i1] <= arr[i2]) {
			link[iResult] = i1;
			iResult = i1; i1 = link[i1];
		}
		else{
			link[iResult] = i2;
			iResult = i2; i2 = link[i2];
		}

	if(i1 == 0) link[iResult] = i2;
	else link[iResult] = i1;
	return link[0];
}


int mergeSort(int* arr,int* link,int left,int right)
{
	if(left>=right) return left;
	int mid = (left+right)/2;
	return listMerge(arr,link,
			mergeSort(arr,link,left,mid),
			mergeSort(arr,link,mid+1,right));
}


int main()
{
	int num;
	int *arr;
	int *link;

	cout<<"배열의 크기를 입력하시요 :";cin>>num;
	arr = new int[num];
	link = new int[num];

	long start,stop;
	long init_start,init_stop;

	time(&start);

	for(int j = 0;j<300000;j++) {

		for(int k = 0 ; k<num; k++)
			arr[k] = num-k;

		for(int k = 0; k<num; k++)
			link[k] = 0;

		int i = mergeSort(arr,link,0,num-1);
		copy(link+1,link+num,arr);
		arr[num-1] = i;
	}

	time(&stop);

	time(&init_start);

	for(int i = 0;i<300000;i++) {

		copy(link+1,link+num,arr);
		arr[num-1] = i;
	}

	time(&init_stop);

	cout<<"Time : "<<(stop-start)-(init_stop-init_start)<<endl;

	cout<<endl;


	return 0;
}
