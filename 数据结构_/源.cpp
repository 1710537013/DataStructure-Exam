#include <iostream>
#include "Linearlist.h"
#include "LinearQue.h"
#include"Graph.h"
#include "Sort.h"
#include"Tree.h"

using namespace std;
void SeqListFunc(SeqList& seqList);
void LinkFunc();
void Print(const int arr[],int start, int size );
void GraphFun();
void TreeFun();

int main()
{	
	//GraphFun();
	//B.LevelOrderSearch(biTree);
	TreeFun();
	return 0;
}
void TreeFun()
{
	BiTree biTree;
	BiTreeClass B;
	B.CreateBiTree(biTree);
	//B.InOrderSearch(biTree);
	//B.CreateThreadTree(biTree);
	//B.WithThreadSearch(biTree);
	B.NonRecursionInOrder(biTree);
}
void GraphFun()
{
	Graph GFun;
	GraphAdjList grapAdList;
	GFun.CreateAdjList(grapAdList);
	//GFun.BFSTraverse(grapAdList);
	//string str = GFun.LianTongGraph(grapAdList) ? "连通" : "不连通";
	//string str = GFun.ExistCircle(grapAdList) ? "有环" : "无环";
/*	string str = GFun.IsTree(grapAdList) ? "是生成树":"不是生成树";
	cout << str << endl;
	*/
	
}
void SortFun()
{
	Sort sort;
	int a[] = { -1, 3,2,1,4,5,2,10,4 };   //  start = 1, size = 8
	int a2[] = { -1, 3,2,1,20,4,5,2,10,4 };   //  start = 0, size = 10

	sort.ShellSort(a2, 10);


	Print(a2, 0, 9);
}
void SeqListFunc(SeqList& seqList)
{
	SeqListClass sqListClass;
	sqListClass.InitSqList(seqList);
	sqListClass.ListInsert(seqList, 1, 10);
	sqListClass.ListInsert(seqList, 2, 43);
	sqListClass.ListInsert(seqList, 2, 421);
	sqListClass.ListInsert(seqList, 4, 1);
	sqListClass.ListInsert(seqList, 1, 4);
	sqListClass.PrintList(seqList);
}

void LinkFunc()
{
	LinkListClass linkClass;
	LinkList head;		
	linkClass.InitLinkList(head);
	linkClass.CreateListTail(head, 1);
	linkClass.ListInsert(head, 1, 999);
	//cout << linkClass.LocateElem(head,5) << endl;
	int i;
	linkClass.ListDelete(head, 3, &i);
	linkClass.PrintList(head);
}

void Print(const int arr[],int start,  int size)
{
	cout << "排序结果: " << endl;
	for (int i = start; i <= size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}