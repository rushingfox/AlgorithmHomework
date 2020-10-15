#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

const int n = 3;
const int m = 2;

void dfs(int, vector<int>, int[m]);

int main()
{
	int temp[m];
	for (int i = 0; i < m; i++)
	{
		temp[i] = 0;
	}
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		a.push_back(i + 1);
	}
	cout << "the result is below:" << endl;
	dfs(0, a, temp);
	system("pause");
}

void dfs(int num,vector<int> a,int b[m])
{
	if (num>=m)
	{
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			cout << " " << b[i];
		}
	}
	else
	{
		for (int i = 0; i < a.capacity(); i++)
		{
			b[num] = a[i];
			a.erase(a.begin() + i);
			dfs(num + 1, a, b);

			a.insert(a.begin() + i, b[num]);//backtracking
			b[num] = 0;
		}
	}
}