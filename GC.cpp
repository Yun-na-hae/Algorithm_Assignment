#include <iostream>
#define N 25

using namespace std;

int W[N+1][N+1];

int vcolor[N+1];
int m ;
int num = 0;

bool promising (int i)
{
	int j;
	bool onoff;
	onoff = true;
	j = 1;
	while(j<i && onoff){
		if(W[i][j] == 1 && vcolor[i] == vcolor[j])
			onoff = false;
		j++;
	}
	return onoff;
}

void m_coloring(int i)
{
	int color;
	if(promising(i)){
		if(i == N)
		{
			num = num+1;
	//		cout<<"________"<<num<<"________"<<endl;
	//		for(int k = 1;k<=N;k++)
	//			cout<<"V"<<k<<" = "<<vcolor[k]<<"  ";
	//		cout<<endl;
		}
		else
		{
			for(color = 1;color <= m; color++)
			{
				vcolor[i+1] = color;
				m_coloring(i+1);
				vcolor[i+1] = 0;
			}
		}
	}
}

int main()
{
	for(int i = 0;i<N+1;i++)
		for(int j = 0;j<N+1;j++)
			W[i][j] = 0;

	W[2][1] = W[1][2] = 1;
	W[3][2] = W[2][3] = 1;
	W[4][3] = W[3][4] = 1;
	W[5][1] = W[1][5] = 1;
	W[5][2] = W[2][5] = 1;
	W[5][3] = W[3][5] = 1;
	W[6][1] = W[1][6] = 1;
	W[6][5] = W[5][6] = 1;
	W[7][6] = W[6][7] = 1;
	W[8][6] = W[6][8] = 1;
	W[8][7] = W[7][8] = 1;
	W[9][7] = W[7][9] = 1;
	W[9][8] = W[8][9] = 1;
	W[10][6] = W[6][10] = 1;
	W[10][7] = W[7][10] = 1;
	W[10][9] = W[9][10] = 1;
	W[11][5] = W[5][11] = 1;
	W[11][6] = W[6][11] = 1;
	W[11][10] = W[10][11] = 1;
	W[12][5] = W[5][12] = 1;
	W[12][11] = W[11][12] = 1;
	W[13][3] = W[3][13] = 1;
	W[13][4] = W[4][13] = 1;
	W[13][20] = W[20][13] = 1;
	W[13][12] = W[12][13] = 1;
	W[15][14] = W[14][15] = 1;
	W[16][14] = W[14][16] = 1;
	W[16][15] = W[15][16] = 1;
	W[17][9] = W[9][17] = 1;
	W[17][14] = W[14][17] = 1;
	W[17][16] = W[16][17] = 1;
	W[18][9] = W[9][18] = 1;
	W[18][17] = W[17][18] = 1;
	W[19][10] = W[10][19] = 1;
	W[19][11] = W[11][19] = 1;
	W[19][18] = W[18][19] = 1;
	W[20][11] = W[11][20] = 1;
	W[20][12] = W[12][20] = 1;
	W[20][13] = W[13][20] = 1;
	W[21][11] = W[11][21] = 1;
	W[21][19] = W[19][21] = 1;
	W[21][20] = W[20][21] = 1;
	W[22][18] = W[18][22] = 1;
	W[22][19] = W[19][22] = 1;
	W[22][21] = W[21][22] = 1;
	W[23][16] = W[16][23] = 1;
	W[23][17] = W[17][23] = 1;
	W[23][18] = W[18][23] = 1;
	W[23][22] = W[22][23] = 1;
	W[24][22] = W[22][24] = 1;
	W[25][21] = W[21][25] = 1;
	W[25][22] = W[22][25] = 1;
	W[25][24] = W[24][25] = 1;


	cout<<"Enter the number of color : ";
	cin>>m;

	m_coloring(0);

	if(num==0)
		cout<<"The number of color is insufficient"<<endl;
	else
		cout<<"The number of color-case is "<<num<<endl;
	
	return 0;
}
