#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


int fs_i(int num)
{
	int* f = new int[num];

	f[0] = 0;

	if(num>0)
	{
		f[1] = 1;
		for(int i = 2;i<num;i++)
			f[i] = f[i-1]+f[i-2];
	}
	return f[num-1];
}


int main()
{
	int num;

	cout<<"숫자를 입력하세요 : ";cin>>num;

	long start, stop;
	long init_start, init_stop;

	time(&start);

	for(int i = 0;i<3000000;i++)
		int result = fs_i(num);

	time(&stop);

	cout<<"Time : "<<stop-start<<endl;

	return 0;
}
