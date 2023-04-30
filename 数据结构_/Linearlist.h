#pragma once
#include <cstdlib>
#include<iostream>

using namespace std;
#define MaxSize 6
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length ;
}SqList;
typedef struct
{
	ElemType* data;
	int maxSize ;
	int length ;
}SeqList;
typedef struct DNode{
	ElemType data;
	struct DNode *next, * prior;
}DNode, *DLinkList;

typedef struct LNode
{
	struct LNode* next;
	ElemType data;
}LinkNode ,*LinkList;

class SeqListClass
{
public:
	void InitSqList(SeqList& seqList);
	int LocateElem(SeqList seqList, ElemType e);
	bool GetElem(SeqList seqList, int index,ElemType& e);
	void ListInsert(SeqList& seqList, int index, ElemType e);
	void ListDelete(SeqList& seqList, int index);
	void PrintList(SeqList seqList);
	void Destroy(SeqList& seqList);
};

class LinkListClass {
public:
	void InitLinkList(LinkList& prt);
	void CreateListTail(LinkList& L, int n);
	void CreateListHead(LinkList& L, int n);
	int LocateElem(LinkList head, ElemType e);
	void ListInsert(LinkList& head, int index, ElemType e);
	void PrintList(LinkList head);
	bool IsEmpty(LinkList head);
	void ListDelete(LinkList& head, int i, ElemType* e);
private:
	LinkNode* GetNode(LinkList head, int index);
};

class DLinkListClass {
public:
	void Init(DLinkList& head);
	void Insert(DLinkList& head,int n);
	void Delete(DLinkList& head,int index);
	void Print(DLinkList head);
};

