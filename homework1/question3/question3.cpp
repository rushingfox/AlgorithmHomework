#include "Btree.h"//https://blog.csdn.net/ljp1919/article/details/47804695 利用此文的讲解进行了对同一个解决方案中的另一个项目中的头文件Btree.h的引用

int findnode(BTNode * bt, int x,int level)//level represents the present level
{
	level++;
	if (bt==NULL)
	{
		return 0;
	}
	else
	{
		if (bt->data==x)
		{
			return level;
		}
		else
		{
			int lnum = findnode(bt->lchild, x, level);
			int rnum = findnode(bt->rchild, x, level);
			return lnum >= rnum ? lnum : rnum;
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
	cout << "please enter the x value" << endl;
	int x;
	cin >> x;
	cout << findnode(bt, x,0);
	system("pause");
}