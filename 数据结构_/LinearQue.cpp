#include "LinearQue.h"

void LinearQue::Ques03(SeqList& L, ElemType x)
{
	int index = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[index++] = L.data[i];
		}
	}
	L.length = index + 1;

	/*
		int	k = 0;
		for (int i = 0; i < L.length; i++)
		{
			if (L.data[i] == x)
			{
				k++;
			}
			else
			{
				L.data[i - x] = L.data[i];
			}
		}
		L.length -= x;
	*/
}

void LinearQue::Ques06(SeqList& L)
{
	if (L.length == 0)
		return;
	int left = 0;
	for (int right = 1; right < L.length; right++)
	{
		if (L.data[left] != L.data[right])
		{
			L.data[++left] = L.data[right];
		}
	}

	L.length = left + 1;
}
// 转换两段元素位置m>= 1,   n<= length
void LinearQue::Ques08(SeqList& L, int m, int n)
{
	if (m >= n)
		return;
	m--;
	n--;
	int tem;
	while (m <= (m + n) / 2)
	{
		tem = L.data[m];
		L.data[m] = L.data[n];
		L.data[n] = tem;
		m++;
		n--;
	}
}

void LinearQue::Ques10(SeqList& L, int p)
{
	p = p % L.length ;
	Ques08(L, 1, L.length);
	Ques08(L, 1, L.length - p);
	Ques08(L, L.length - p + 1, L.length);
	cout << "Reverse successfully" << endl;
}
