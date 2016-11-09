#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


int fs_r(int num)
{
	if(num<=1)
		return num;
	else
		return fs_r(num-1) + fs_r(num-2);

}


int main()
{
	int num;
	int result;

	cout<<"숫자를 입력하세요 : ";cin>>num;

	long start,stop;

	time(&start);

//	for(int i = 0;i<300;i++)
		result = fs_r(num);

	time(&stop);

	cout<<"Time : "<<stop-start<<endl;

	return 0;
}

