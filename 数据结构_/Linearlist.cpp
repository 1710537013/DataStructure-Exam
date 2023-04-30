#include "Linearlist.h"

#pragma region 线性表
void SeqListClass::InitSqList(SeqList& seqList)
{
	// seqList.data = (ElemType*)malloc(sizeof(ElemType) * 8);	c语言申请格式
	seqList.data = new ElemType[8];							   // c++申请格式
	seqList.maxSize = 8;
	seqList.length = 0;
}

int SeqListClass::LocateElem(SeqList seqList, ElemType e)
{
	for (int i = 0; i < seqList.length; i++)
	{
		if (e == seqList.data[i])
			return ++i;
	}
	return 0;
}


bool SeqListClass::GetElem(SeqList seqList, int index, ElemType& e)
{
	if (index< 1 || index> seqList.length)
		return false;
	return seqList.data[index - 1];
}

void SeqListClass::ListInsert(SeqList& seqList, int index, ElemType e)
{
	if (index< 1 || index> seqList.length + 1)		// 增加新空间
	{
		cout << "invalid input" << endl;
		return;

	}
	//申请空间
	if (seqList.length >= seqList.maxSize)
	{
		SeqList tem = seqList;
		seqList.data = new ElemType[seqList.maxSize + 5];
		seqList.maxSize += 5;
		for (int i = 0; i < tem.maxSize; i++)
		{
			seqList.data[i] = tem.data[i];
		}
		delete[] tem.data;
	}

	for (int i = seqList.length; i > index - 1; i--)
	{
		seqList.data[i] = seqList.data[i - 1];
	}

	seqList.length++;
	seqList.data[index - 1] = e;
}

void SeqListClass::ListDelete(SeqList& seqList, int index)
{
	if (index < 1 || index> seqList.length)
	{
		cout << "invalid input" << endl;
		return;		//提示报错
	}
	for (int i = index - 1; i < seqList.length - 1; i++)
	{
		seqList.data[i] = seqList.data[i + 1];
	}
	seqList.length--;
}

void SeqListClass::PrintList(SeqList seqList)
{
	for (int i = 0; i < seqList.length; i++)
	{
		cout << seqList.data[i] << "  ";
	}
	cout << endl;
}

void SeqListClass::Destroy(SeqList& seqList)
{
	delete[] seqList.data;
	cout << "Delete successfully";
}
#pragma endregion
#pragma region 单链表

//初始化
void LinkListClass::InitLinkList(LinkList& ptr)
{
	ptr = new LinkNode;
	if (!ptr)
	{
		cout << "初始化失败" << endl;
		return;
	}
	ptr->next = NULL;
	cout << "初始化成功" << endl;
}

//获取 元素位序
int LinkListClass::LocateElem(LinkList head, ElemType e)
{
	int index = 0;
	while (head->next != NULL)
	{
		head = head->next;
		index++;
		if (head->data == e)
		{
			return index;
		}
	}
	return 0;
}
void LinkListClass::ListDelete(LinkList& head, int i, ElemType* e)
{
	if (i < 1)
	{
		cout << "invalid input" << endl;
		return;
	}
	LinkList tem = GetNode(head, i - 1);
	if (tem)
	{
		if (tem->next == NULL)
		{
			cout << "invalid input" << endl;
			return;
		}
		LinkList p = tem->next;
		tem->next = p->next;
		*e = p->data;
		delete p;
	}
}
// 打印节点
void LinkListClass::PrintList(LinkList head)
{
	cout << "打印结果: " << endl;
	while (head->next != NULL)
	{
		head = head->next;		//头结点不打印
		cout << head->data << " ";
	}
}
// 是否为空
bool LinkListClass::IsEmpty(LinkList head)
{
	return head->next == NULL ? true : false;
}
// 尾插
void LinkListClass::CreateListTail(LinkList& head, int n)
{
	if (n < 1)
	{
		cout << "invalid input" << endl;
		return;
	}
	LinkList p = head;
	ElemType e;

	cout << "Please, inputting data:  (tail insert)" << endl;
	while (n != 0)
	{
		cin >> e;
		LinkList tem = (LinkList)malloc(sizeof(LinkNode));
		tem->data = e;
		tem->next = p->next;
		p->next = tem;
		p = tem;
		n--;
	}
}
// 头插
void LinkListClass::CreateListHead(LinkList& head, int n)
{
	if (n < 1)
	{
		cout << "invalid input" << endl;
		return;
	}

	cout << "Please, inputting data:    (head insert)" << endl;
	ElemType e;
	while (n != 0)
	{
		cin >> e;
		LinkList tem = new LinkNode;
		tem->data = e;
		tem->next = head->next;
		head->next = tem;
		n--;
	}
}
// 获取节点
LinkNode* LinkListClass::GetNode(LinkList head, int index)
{
	if (index < 0)
	{
		cout << "invalid input" << endl;
		return NULL;
	}
	if (index == 0)
	{
		return head;
	}
	int i = 0;
	while (head->next != NULL && i < index)
	{
		head = head->next;
		i++;
	}
	if (i == index)
	{
		return head;
	}
	else
	{
		cout << "invalid input" << endl;
		return NULL;
	}
}
// 前插
void LinkListClass::ListInsert(LinkList& head, int index, ElemType e)
{
	if (index < 1)
	{
		cout << "invalid input" << endl;
		return;
	}
	LinkList p = GetNode(head, index);
	if (p == NULL)
	{
		return;
	}
	// 将前插转化为后插， 然后再交换数据，各有优缺点
	LinkList tem = new LinkNode;
	tem->data = e;
	tem->next = p->next;
	p->next = tem;

	tem->data = tem->data ^ p->data;
	p->data = tem->data ^ p->data;
	tem->data = tem->data ^ p->data;
}
#pragma endregion

void DLinkListClass::Init(DLinkList& head)
{
	head = new DNode;
	head->next = head;
}
//头插
void  DLinkListClass::Insert(DLinkList& head, int n)
{
	if (n < 1)
	{
		cout << "invalid input" << endl;
		return;
	}

	cout << "Please, inputting data:   " << endl;
	ElemType e;
	while (n != 0)
	{
		cin >> e;
		DLinkList tem = new DNode;
		tem->data = e;
		tem->next = head->next;
		head->prior = tem;
		tem->prior = head;
		head->next = tem;
		n--;
	}
}

void DLinkListClass::Delete(DLinkList& head, int index)
{
	if (index < 1)
	{
		cout << "invalid input" << endl;
		return;
	}
	int i = 0;
	DLinkList tem = head;
	while (tem != head&& i < index)
	{
		tem = tem->next;
		i++;
	}
	if (tem != head)
	{
		tem->prior->next = tem->next;
		tem->next->prior = tem->prior;
		delete tem;
	}else
		cout << "invalid input" << endl;
}

void DLinkListClass::Print(DLinkList head)
{
	head = head->next;
	while (head->next != NULL)
	{
		cout << head->data << "  ";
	}
}