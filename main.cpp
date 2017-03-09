#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<int*> output;

struct node
{
	int maxSpeed;
	int fee;
};
struct cusnode
{
	int id;
	int linkToNod;
	int need;
};

int DFS(int a,int b)
{
	
}
int find_serveridx(int *temp ,int *serveridx,int n)
{
	int t=9999;
	int cnt = 0;
	for(int j = 0;j<n;++j)
	{
		for(int i = 0;i<n;++i)
		{
			if(temp[i]<t)
			{
				t=temp[i];
				cnt=i;
				temp[i]=999999;
			}
		}
		serveridx[j]=cnt;
	}
	
}

void programming(int *serveridx,int *cus,int n)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=i;+j)
		{
			int *temp;
			temp=new int[j+1];
			temp[j]=DFS(cus[i],serveridx[j]);
			

			delete temp;
		}
	}
}

int main()
{
	int initial[3] = { 0 };
	int costOfServer = 0;//��Ƶ���ݷ������ɱ�
	node **nod;//�����ڵ�
	cusnode *cusnod;//���ѽڵ�
	int **D;
	int **P;
	ifstream Case("case0.txt");

	for (int i = 0; i < 3; ++i)
		Case >> initial[i];//initial[0]Ϊ�����ڵ�������initial[1]Ϊ��·����initial[2]Ϊ���ѽڵ���
	Case >> costOfServer;

	nod = new node*[initial[0]];
	for (int i = 0; i < initial[0]; ++i)
		nod[i] = new node[initial[0]];

	D = new int*[initial[0]];
	for (int i = 0; i < initial[0]; ++i)
		D[i] = new int[initial[0]];

	P = new int*[initial[0]];
	for (int i = 0; i < initial[0]; ++i)
		P[i] = new int[initial[0]];

	cusnod = new cusnode[initial[2]];
	for (int i = 0; i < initial[0]; ++i)
	{
		for (int j = 0; j < initial[0]; ++j)
		{
			nod[i][j].maxSpeed = 0;
			nod[i][j].fee = 9999;
			D[i][j] = 9999;
		}
	}

	for (int i = 0; i < initial[1]; ++i)
	{
		int temp[4];
		for (int j = 0; j < 4; ++j)
		{
			Case >> temp[j];
		}
		nod[temp[0]][temp[1]].maxSpeed = temp[2];
		nod[temp[0]][temp[1]].fee = temp[3];
		nod[temp[1]][temp[0]].maxSpeed = temp[2];
		nod[temp[1]][temp[0]].fee = temp[3];
		D[temp[0]][temp[1]] = temp[3];
		D[temp[1]][temp[0]] = temp[3];
	}

	for (int i = 0; i < initial[2]; i++)
	{
		int temp[3];
		for (int j = 0; j < 3; ++j)
		{
			Case >> temp[j];
		}
		cusnod[i].id = temp[0];
		cusnod[i].linkToNod = temp[1];
		cusnod[i].need = temp[2];
	}
	Case.close();
	int *cus;
	cus = new int[initial[2]];
	
	
	for (int i = 0; i < initial[2]; ++i)
		cus[i] = cusnod[i].linkToNod;

	for (int i = 0; i < initial[0]; ++i)
	{
		for (int j = 0; j < initial[0]; ++j)
		{
			P[i][j] = j;
		}
	}
	for (int i = 0; i < initial[0]; ++i)
	{
		for (int j = 0; j < initial[0]; ++j)
		{
			for (int k = 0; k < initial[0]; ++k)
			{
				if (D[j][k] > D[j][i] + D[i][k])
				{

					D[j][k] = D[j][i] + D[i][k];
				
					P[j][k] = P[j][i];
				}
			}
		}
	}
	int sum=0;
	int *temp;
	temp = new int[initial[2]];
	for (int i = 0; i < initial[0]; ++i)
	{
		for (int j = 0;j < initial[2]; ++j)
		{
			sum += D[cus[j]][i];
		}
		temp[i] = sum;
		sum = 0;
		//cout <<i <<"\t"<<temp[i] << endl;
	}
	int *serveridx;
	serveridx = new int[initial[2]];
	find_serveridx(temp,serveridx,initial[2]);	
	
	
	system("pause");
	return 0;
}
