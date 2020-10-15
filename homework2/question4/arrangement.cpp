#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[] = { 1,1,2 };
const int n = 3;

void dfs(int, int[]);
bool repeated(int[], int, int);

int main()
{
	cout << "all the arrangement was below:";
	dfs(0, a);
	system("pause");
}

void dfs(int num,int a[])
{
	if (num>=n)
	{
		cout << endl;
		//a new arrangement was found and printed
		for (int i = 0; i < n; i++)
		{
			cout << " " << a[i];
		}
	}
	else
	{
		dfs(num + 1, a);                //default route
		for (int i = num+1; i < n; i++) //possible routes
		{
			if (!repeated(a,num,i))
			{
				int transit = a[num];
				a[num] = a[i];
				a[i] = transit;
				dfs(num + 1, a);

				a[i] = a[num];//backtracking
				a[num] = transit;
			}
		}
	}
}

bool repeated(int a[],int num,int i)
{
	for (int j = num; j < i; j++)
	{
		if (a[i]==a[j])
		{
			return true;
		}
	}
	return false;
}