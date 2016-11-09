#include <iostream>
#include <cmath>

#define N 4 // Number of Vertexs

using namespace std;

char V[N] = {'a','b','c','d'}; // V1 = a, V2 = b, V3 = c, V4 = d, V5 = e
int W[N][N] = {{0,2,9,1000},{1,0,6,4},{1000,7,0,8},{6,3,1000,0}}; // edge 가 없을 경우 가중치 1000으로 지정

void travel()
{
	int path1,path2,path3;
	int i,j,k,s,t,v;
	int D[N][(int)(pow(2,N-1))];
	int P[N][(int)(pow(2,N-1))];
	P[0][0] = 1; P[1][0] = 2; P[2][0] = 3; P[3][0] = 4;

	for(i = 1 ; i < N ; i++)
		D[i][0] = W[i][0];

	for(k = 1 ; k <= N-2 ; k++)
	{
		if(k == 1){	
			for(j = 1 ; j < N ; j++)
			{
				if(j == 1)	//A = {v2}, i = v3,v4
				{
					D[2][j] = W[2][j] + D[j][0];
					D[3][j] = W[3][j] + D[j][0];

				}else if(j == 2)	//A = {v3}, i = v2,v4
				{
					D[1][j] = W[1][j] + D[j][0];
					D[3][j] = W[3][j] + D[j][0];

				}else if(j == 3)	//A = {v4}, i = v2,v3
				{
					D[1][j] = W[1][j] + D[j][0];
					D[2][j] = W[2][j] + D[j][0];

				}				
			}

		}else if( k == 2 ){
			for(j = N ; j < pow(2,N-1) - 1 ; j++)
			{
				if(j == 4)	//A = {v2,v3}, i = 4
				{
					if((W[3][1] + D[1][2]) <= (W[3][2] + D[2][1]))
					{
						D[3][j] = W[j][1] + D[1][2];
						s = 1;
					}
					else
					{
						D[3][j] = W[j][2] + D[2][1];
						s = 2;
					}
				}else if(j == 5)	//A = {v2,v4}, i = 3
				{
					if((W[2][1] + D[1][3]) <= (W[2][3] + D[3][1]))
					{
						D[2][j] = W[2][1] + D[1][3];
						t = 1;
					}
					else
					{
						D[2][j] = W[2][3] + D[3][1];
						t = 2;
					}
				}else if(j == 6)	//A = {v3,v4}, i = 2
				{
					if((W[1][2] + D[2][3]) <= (W[1][3] + D[3][2]))
					{
						D[1][j] = W[1][2] + D[2][3];
						v = 1;
					}
					else
					{
						D[1][j] = W[1][3] + D[3][2];
						v = 2;
					}
				}
			}
		}
	}
	if((W[0][1] + D[1][6]) <= (W[0][2] + D[2][5]))
	{
		if((W[0][1] + D[1][6]) <= (W[0][3] + D[3][4]))
		{
			path1 = 2;
			D[0][(int)(pow(2,N-1)-1)] = W[0][1] + D[1][6]; 	// v1->v2 로 결정
			P[0][(int)(pow(2,N-1)-1)] = path1;
			if(v == 1)
			{
				path2 = 3;
				path3 = 4;
				P[1][6] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[1][6]<<" -> "<<"V"<<P[3][0]<<" -> "<<"V1"<<endl;
			}else if(v == 2)
			{
				path2 = 4;
				path3 = 3;
				P[1][6] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[1][6]<<" -> "<<"V"<<P[2][0]<<" -> "<<"V1"<<endl;
			}
		}
		else
		{
			path1 = 4;
			D[0][(int)(pow(2,N-1)-1)] = W[0][3] + D[3][4];	// v1->v4 로 결정
			P[0][(int)(pow(2,N-1)-1)] = path1;
			if(s == 1)
			{
				path2 = 2;
				path3 = 3;
				P[3][4] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[3][4]<<" -> "<<"V"<<P[2][0]<<" -> "<<"V1"<<endl;

			}else if(s == 2)
			{
				path2 = 3;
				path3 = 2;
				P[3][4] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[3][4]<<" -> "<<"V"<<P[1][0]<<" -> "<<"V1"<<endl;
			}
		}
	}else
	{
		if((W[0][2] + D[2][5]) <= (W[0][3] + D[3][4]))
		{
			path1 = 3;
			D[0][(int)(pow(2,N-1)-1)] = W[0][2] + D[2][5];	// v1->v3 로 결정
			P[0][(int)(pow(2,N-1)-1)] = path1;
			if(t == 1)
			{
				path2 = 2;
				path3 = 4;
				P[2][5] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[2][5]<<" -> "<<"V"<<P[3][0]<<" -> "<<"V1"<<endl;
			}else if(t == 2)
			{
				path2 = 4;
				path3 = 2;
				P[2][5] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[2][5]<<" -> "<<"V"<<P[1][0]<<" -> "<<"V1"<<endl;
			}
		}
		else
		{
			path1 = 4;
			D[0][(int)(pow(2,N-1)-1)] = W[0][3] + D[3][4];	//v1->v4 로 결정 
			P[0][(int)(pow(2,N-1)-1)] = path1;
			if(s == 1)
			{
				path2 = 2;
				path3 = 3;
				P[3][4] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[3][4]<<" -> "<<"V"<<P[2][0]<<" -> "<<"V1"<<endl;
			}else if(s == 2)
			{
				path2 = 3;
				path3 = 2;
				P[3][4] = path2;
				cout<<"V1 -> "<<"V"<<P[0][7]<<" -> "<<"V"<<P[3][4]<<" -> "<<"V"<<P[1][0]<<" -> "<<"V1"<<endl;
			}
		}
	}

}

int main()
{
	int num = N;

	travel();

	return 0;
}


