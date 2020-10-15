#include "Btree.h"

int sum(BTNode * bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	if (bt->lchild == NULL && bt->rchild == NULL)
	{
		return bt->data;
	}
	return (sum(bt->lchild) + sum(bt->rchild));
}

int main()
{
	cout << "please enter the number of vector" << endl;
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	cout << "please enter vector a" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "please enter vector b" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	BTNode * bt;
	bt = CreateBTree(&a[0], &b[0], n);
	DispBTree(bt);
	cout << sum(bt);
	system("pause");
}
