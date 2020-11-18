#include<iostream>
#include<vector>
using namespace std;

const string arr1 = "apple";
const string arr2 = "peach";
const int m = 5;
const int n = 5;
vector<char> result;

void solvedp(int(&dp)[m + 1][n + 1]);

int main()
{
	int dp[m+1][n+1];
	solvedp(dp);
	int i = m ;
	int j = n ;
	while (i!=0||j!=0)
	{
		if (i>=1&&dp[i-1][j]==dp[i][j])
		{
			result.push_back(arr1[i - 1]);
			i-=1;
		}
		else if (j>=1&&dp[i][j-1]==dp[i][j])
		{
			result.push_back(arr2[j - 1]);
			j -= 1;
		}
		else if (i>=1&&j>=1&&dp[i][j-1]!=dp[i][j]&&dp[i-1][j]!=dp[i][j])//此时的arr1[i-1]和arr2[j-1]相等
		{
			result.push_back(arr1[i - 1]);
			i -= 1;
			j -= 1;
		}
	}
	for (int i = result.size()-1; i>=0; i--)
	{
		cout << result[i];
	}
	system("pause");
	return 0;
}

void solvedp(int (&dp)[m+1][n+1])
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i==0||j==0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (arr1[i - 1] == arr2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
				}
			}
		}
	}
}