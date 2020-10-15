#pragma once
#include <iostream>
#include<vector>
using namespace std;

struct BTNode
{
	int data;
	struct BTNode *lchild, *rchild;
};

BTNode *CreateBTree(int a[], int b[], int n) //ʹ���������к���������
{
	int k;
	if (n <= 0)
		return NULL;
	BTNode *bt = (BTNode *)malloc(sizeof(BTNode));
	bt->data = a[0];
	for (k = 0; k < n; k++)
		if (a[0] == b[k])
			break;
	//�ݹ鴴��������
	bt->lchild = CreateBTree(a + 1, b, k);
	//�ݹ鴴��������
	bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - 1 - k);
	return bt;
}

void DispBTree(BTNode *bt)
{
	if (bt != NULL) 
	{   
		cout << bt->data << " ";
		if (bt->lchild!=NULL||bt->rchild!=NULL)
		{
			cout << "(";
			DispBTree(bt->lchild);
			if (bt->rchild!=NULL)
			{
				cout << ",";
			}
			DispBTree(bt->rchild);
			cout << ")";
		}
	}
}

void DestroyBTree(BTNode *bt)
{
	if (bt == NULL) {
		return;
	}
	else {
		DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}