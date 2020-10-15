#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

vector<int> w = { 1,2,3,4 };
const int n = 4;
const int W = 10;
int Result[n];
int total=0;

bool dfs(int, int, int, int[]);

int main()
{
	int temp[n];
	for (int i = 0; i < n; i++)
	{
		total += w[i];
		Result[i] = 0;
		temp[i] = 0;
	}

	if (dfs(0,total,0,temp))
	{
		cout << "the result whose total is equal to " << W << " was as showed below:" << endl;
		for (int i = 0; i < n; i++)
		{
			if (Result[i]==1)
			{
				cout << "No." <<i<<"  item was selected!" << endl;
			}
		}
	}

	system("pause");
}

bool dfs(int presentweight,int restweight,int i,int temp[])
{
	if (presentweight==W)
	{
		for (int i = 0; i < n; i++)
		{
			Result[i] = temp[i];
		}
		return true;
	}
	else
	{
		if (i>=n)
		{
			//it still does not meet the requirement even it has turned to the end
		}
		else
		{
			temp[i] = 1;
			if (presentweight+w[i]<=W)//we only preserve the nodes whose weight is still not beyond the aimed number
			{
				if (dfs(presentweight + w[i], restweight - w[i], i + 1, temp))
				{
					return true;
				}
			}
			temp[i] = 0;
			if (presentweight+restweight-w[i]>=W)//we only preserve the nodes whose weight still has the potential for meeting the number requirements 
			{
				if (dfs(presentweight, restweight - w[i], i + 1, temp))
				{
					return true;
				}
			}
		}
	}
	return false;//the final exit for this function
}