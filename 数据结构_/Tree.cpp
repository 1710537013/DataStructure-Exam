#include<iostream>
#include<queue>
#include<stack>

using namespace std;

#include "Tree.h"

/// <summary>
/// Create Tree with PreOrder
/// </summary>
int index = 0;
int str[] = { 1,2,3,0,0,4,0,0,5,6,0,0,0 };
void BiTreeClass::InThread(BiTree& T)
{
	if (T == NULL)	return;
	InThread(T->lchild);
	if (T->lchild== NULL)
	{
		T->lchild = pre;
		T->ltag = 1;
	}
	if (pre && !pre->rchild)
	{
		pre->rchild = T;
		pre->rtag=1;
	}
	pre = T;
	InThread(T->rchild);
}
void BiTreeClass::CreateThreadTree(BiTree& T)
{
	pre = NULL;
	InThread(T);		// 中序方式构建
	if (!T->rchild)
		T->rtag = 1;
}
void BiTreeClass::WithThreadSearch(BiTree T)
{
	for (BiTree tem = SearchFirstNode(T); tem != NULL; tem = SearchNextNode(tem))
		cout << tem->data << " ";
}
BiTree BiTreeClass::SearchNextNode(BiTree T)
{
	if (T->rtag == 1)
		return T->rchild;
	else
		return SearchFirstNode(T->rchild);
}

BiTree BiTreeClass::SearchFirstNode(BiTree T)
{
	if (T == NULL) return NULL;
	while (T->ltag == 0)	T = T->lchild;
	return T;
}
void BiTreeClass::CreateBiTree(BiTree& T)
{
	int ch = str[index++];

	if (ch == 0)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiNode));
		T->ltag = 0;
		T->rtag = 0;
		T->data = ch; /* 生成根结点 */
		CreateBiTree(T->lchild); /* 构造左子树 */
		CreateBiTree(T->rchild); /* 构造右子树 */
	}
}

void BiTreeClass::PreOrderSearch(BiTree T)
{
	if (!T) return;

	cout << T->data + " ";
	PreOrderSearch(T->lchild);
	PreOrderSearch(T->rchild);
}

void BiTreeClass::InOrderSearch(BiTree T)
{
	if (!T) return;

	InOrderSearch(T->lchild);
	cout << T->data << " ";
	InOrderSearch(T->rchild);
}

void BiTreeClass::PostOrderSearch(BiTree T)
{
	if (!T) return;
	PostOrderSearch(T->lchild);
	PostOrderSearch(T->rchild);
	cout << T->data + " ";
}

void BiTreeClass::LevelOrderSearch(BiTree T)
{
	queue<BiTree> Q;
	Q.push(T);
	while (!Q.empty())
	{
		BiTree tem = Q.front();
		Q.pop();
		cout << tem->data << " ";
		if (tem->lchild)
		{
			Q.push(tem->lchild);
		}
		if (tem->rchild)
			Q.push(tem->rchild);
	}
}

/// <summary>
/// 中序遍历非递归算法
/// </summary>
/// <param name="T"></param>
void BiTreeClass::NonRecursionInOrder(BiTree T)
{
	stack<BiTree> s;
	while (s.empty()== false|| T)
	{
		while (T)
		{
			s.push(T);
			T = T->lchild;
		}
		T = s.top();
		s.pop();
		cout << T->data << " ";
		T = T->rchild;
	}
}
/// <summary>
/// 前序遍历非递归遍历
/// </summary>
void BiTreeClass::NonRecursionPreOrder(BiTree T)
{
	stack<BiTree> s;
	while (s.empty() == false || T)
	{
		while (T)
		{
			cout << T->data << " ";
			s.push(T);
			T = T->lchild;
		}
		T = s.top()->rchild;
		s.pop();
	}
}
