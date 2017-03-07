#include<iostream>
#include<fstream>
using namespace std;
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
int min(int *p ,int n)
{
	int temp=9999;
	int tmpidex=0;
	for (int i = 0; i < n; ++i)
	{
		if (p[i] < temp)
		{
			temp = p[i];
			tmpidex = i;
		}
	}
	return tmpidex;
}
int findpath(int **P,int i,int j)
{
	if (i == j)
		return -1;
	j = P[i][j];
	return j;
}
int main()
{
	int initial[3] = { 0 };
	int costOfServer = 0;//视频内容服务器成本
	node **nod;//网络节点
	cusnode *cusnod;//消费节点
	int **D;
	int **P;
	ifstream Case("case0.txt");

	for (int i = 0; i < 3; ++i)
		Case >> initial[i];//initial[0]为网络节点数量，initial[1]为链路数，initial[2]为消费节点数
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
	int *first;
	first = new int[initial[2]];
	
	
	for (int i = 0; i < initial[2]; ++i)
		first[i] = cusnod[i].linkToNod;
	//for (int i = 0; i < initial[2]; ++i)
	//	cout << first[i] << endl;
	//cout << endl;
	//
	//	for (int i = 0; i < initial[2]; ++i)
	//	{
	//		for (int j = 0; j < initial[0]; ++j)
	//		{
	//			int temp = 10000;
	//			if (nod[first[i]][j].fee < temp)
	//			{
	//				first[i] = j;
	//				temp = nod[first[i]][j].fee;
	//			}
	//		}
	//	}
	//
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
				sum += D[first[j]][i];
			}
			temp[i] = sum;
			sum = 0;
			//cout <<i <<"\t"<<temp[i] << endl;
		}
	int serveridx;
	serveridx = min(temp, initial[2]);
	cout << serveridx << endl;

	/*int **path;
	path = new int*[initial[2]];
	for (int i = 0; i < initial[2]; ++i) {
		path[i] = new int[100];
	}
	for (int i = 0; i < initial[2]; ++i)
	{
		for (int j = 0; j < 100; j++)
		{
			path[i][j] = -1;
		}
	}
	for (int i = 0; i < initial[2]; ++i)
	{
		int t = serveridx;
		path[i][99] = serveridx;
		for (int j = 0; j < 100; ++j)
		{	
			t = findpath(P, first[i], t);
			if(t>=0)
			path[i][98 - i] = t;
		}
	}*/
	
	system("pause");
	return 0;
}