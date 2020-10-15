#include "Btree.h"//https://blog.csdn.net/ljp1919/article/details/47804695 利用此文的讲解进行了对同一个解决方案中的另一个项目中的头文件Btree.h的引用

int countnum(BTNode * bt, int k)
{
	if (bt==NULL)
	{
		return 0;
	}
	else
	{
		int lnum = countnum(bt->lchild, k);
		int rnum = countnum(bt->rchild, k);
		if (bt->data>=k)
		{
			return lnum + rnum + 1;
		}
		else
		{
			return lnum + rnum;
		}
	}
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
	cout << endl;
	cout << "please enter the k value" << endl;
	int k;
	cin >> k;
	cout << countnum(bt,k);
	system("pause");
}