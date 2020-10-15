#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threefold(int a[],int head, int tail, int s)//for the second ask in this question, I would like to answer"log3(n)" as the time complexity for this algorithm.
{
	if (tail-head<=2)
	{
		for (int i = head; i <= tail; i++)
		{
			if (a[i]==s)
			{
				return i;
			}
		}
		return NULL;
	}
	int OneThird = head + (tail - head) / 3;
	int TwoThirds = head + 2 * (tail - head) / 3;
	if (a[OneThird]==s)
	{
		return OneThird;
	}
	if (a[TwoThirds]==s)
	{
		return TwoThirds;
	}
	if (a[OneThird]>s)
	{
		return threefold(a, head, OneThird, s);
	}
	if (a[TwoThirds]>s)
	{
		return threefold(a, OneThird, TwoThirds, s);
	}
	return threefold(a, TwoThirds, tail, s);
}

int main()
{
	cout << "please enter the number of the array" << endl;
	int n;
	cin >> n;
	vector<int> a(n);
	cout << "please enter the n different integers" << endl;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		a[i] = value;
	}
	sort(&a[0], &a[n - 1] + 1);//I found that the second parameter of STL's sort needs to be the last address plus 1(and &a[n] is false while &a[n-1]+1 is right)
	cout << "the vector has been sorted already:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "please enter the value you are searching for:" << endl;
	int searchnum;
	cin >> searchnum;
	cout << "the label number of the searchnum is:" << endl<<threefold(&a[0],0,n-1,searchnum);
	system("pause");
}