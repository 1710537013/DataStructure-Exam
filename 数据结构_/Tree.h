#include<iostream>

using namespace std;

// 线索二叉树是一种 存储结构，  二叉树是逻辑结构
typedef struct BiNode
{
	int data;
	struct BiNode* lchild, * rchild;
	int ltag, rtag ;
}BiNode, *BiTree;

class BiTreeClass {
public:
	void CreateThreadTree(BiTree& T);
	void WithThreadSearch(BiTree T);
	BiTree SearchNextNode(BiTree T);
	BiTree SearchFirstNode(BiTree T);

	void CreateBiTree(BiTree& T);
	void PreOrderSearch(BiTree T);
	void InOrderSearch(BiTree T);
	void PostOrderSearch(BiTree T);
	void LevelOrderSearch(BiTree T);
	void NonRecursionInOrder(BiTree T);
	void NonRecursionPreOrder(BiTree T);
private:
	BiTree pre;
	void InThread(BiTree& T);
};



