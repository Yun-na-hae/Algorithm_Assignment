#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
void arrInit(int*, const int);
int SequentialSearch(int num,int *arr,int key);
void TimeSearch();
int main(void){
	TimeSearch();
	return 0;
}

int SequentialSearch(int num,int *arr,int key)
{
	int location = 0;

	while(location < num && arr[location] != key)
		location++;

	return location;
}


void arrInit(int *arr, const int size){ //Init array as a descending power
	for(int i = size-1 ; i >= 0; i--){
		arr[i] = size-i-1;
	}
}

void TimeSearch() {
	int a[2014];
	int	n[11]; //a is array of number, n is range of array to survey
	int j,num,k,location;
	const long r[30] = {3000000, 3000000, 2000000, 2000000, 1000000, 1000000,
		1000000, 800000, 800000, 500000, 500000, 25000, 15000, 15000, 10000, 7500, 7000,
		6000, 5000, 5000, 4000, 4000, 3000, 3000 ,2000, 2000, 1000, 1000, 1000, 1000}; //The number of how many repeat loop


	arrInit(a, 2014); //Init array

	for(int i = 0;i<11;i++)
		n[i] = pow(2,i);


	cout<<"___Sequential Search___"<<endl;

	cout <<  "   n   totalTime   runTime" << endl;

	for(j = 0; j < 30; j++)  { // obtain computing times
		long start, stop ;
		long init_start, init_stop;
		time(&start); // start timer
		for (long b = 1,k = 0; b <= r[j]; b++,k++){
			arrInit(a, r[k]);
			location = SequentialSearch(n[j],a,r[k]);
		}
		time(&stop) ; // stop timer
		time(&init_start);
		for(long b = 1,k = 0; b <= r[j]; b++,k++){
			arrInit(a, r[k]);
		}
		time(&init_stop);
		long totalTime = (stop - start) - (init_stop - init_start);
		long double runTime = (long double) (totalTime)/(long double)(r[j]) ;
		cout << "   " << n[j] << "     " << totalTime << "       " << runTime << endl;
	}
	cout << "Times are in hundredths of a second." << endl;
}
