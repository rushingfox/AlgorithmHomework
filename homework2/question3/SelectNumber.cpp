//题目要求：给定若干个正整数a0、a0 、…、an-1 ，从中选出若干数，使它们的和恰好为k，要求找选择元素个数最少的解。
#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int a[] = { 1,4,10,2,6 };
const int totalNum = 5;
const int requiredSum = 7;
int result[totalNum];
int sum = 0;
int minnum = 10000;//represent gigantic

void dfs(int, int, int, int[], int);

int main()
{
	int temp[totalNum];
	for (int i = 0; i < totalNum; i++)
	{
		sum += a[i];
		result[i] = 0;
		temp[i] = 0;
	}
	dfs(0, 0, sum, temp, 0);
	cout << "the result is below:" << endl;
	bool find = false;
	for (int i = 0; i < totalNum; i++)
	{
		if (result[i]==1)
		{
			find = true;
			cout << "No. " << i << " was selected!" << endl;
		}
	}
	if (!find)
	{
		cout << "there is no selection meeting the requirements, not to mention the least num of elements!" << endl;
	}
	system("pause");
}

void dfs(int i, int presentsum, int restsum, int temp[],int num)//num denotes the number of number in temp
{
	if (presentsum==requiredSum && num<minnum)
	{
		for (int i = 0; i < totalNum; i++)
		{
			result[i] = temp[i];
		}
		minnum = num;
	}
	else
	{
		if (i>=totalNum)
		{
			//it still does not meet the requirement even it has turned to the end
		}
		else
		{
			temp[i] = 1;
			num += 1;
			if (presentsum+a[i]<=requiredSum)
			{
				dfs(i + 1, presentsum + a[i], restsum - a[i], temp, num + 1);
			}
			temp[i] = 0;
			num -= 1;
			if (presentsum+restsum-a[i]>=requiredSum)
			{
				dfs(i + 1, presentsum, restsum - a[i], temp, num);
			}
		}
	}
}
