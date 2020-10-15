#include <iostream>
using namespace std;
int solve(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		int sum = 0;
		for (int i = 2; i <= n; i++)
		{
			if (n%i==0)
			{
				sum += solve(n / i);
			}
		}
		return sum;
	}
}

int main()
{
	cout << "please enter the number" << endl;
	int num;
	cin >> num;
	cout << "the result is: " << solve(num) << endl;
	system("pause");
}