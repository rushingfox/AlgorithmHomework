#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_i(int a[],int head, int tail)
{
	if (a[head]==head)
	{
		return head;
	}
	if (a[tail]==tail)
	{
		return tail;
	}
	if (head==tail)
	{
		cout << "the vector does not have a element whose value equals to its label number" << endl;
		return NULL;
	}
	int mid = 0.5*(head + tail);
	if (mid==head)
	{
		cout << "the vector does not have a element whose value equals to its label number" << endl;
		return NULL;
	}
	if (a[mid]==mid)
	{
		return mid;
	}
	else
	{
		if (a[mid]>mid)
		{
			return find_i(a, head, mid);
		}
		else
		{
			return find_i(a, mid, tail);
		}
	}
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
	sort(&a[0],&a[n-1]+1);//I found that the second parameter of STL's sort needs to be the last address plus 1(and &a[n] is false while &a[n-1]+1 is right)
	cout << "the vector has been sorted already:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	cout << endl << "the label is:" << endl<<find_i(&a[0],0,n-1);
	system("pause");
}