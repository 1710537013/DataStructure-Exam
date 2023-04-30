#include "Sort.h"
#include<iostream>
#include<cstdlib>

int* B = (int*)malloc(100 * sizeof(int));

void Sort::Merge(int A[], int low, int high)
{
	int mid = low + (high - low) / 2;
	for (int i = low; i <= high; i++)
	{
		B[i] = A[i];
	}
	int k = low, i, j;
	for (i = low, j = mid + 1; i <= mid && j <= high; k++)
	{
		if (B[i] <= B[j])
		{
			A[k] = B[i++];
		}
		else
		{
			A[k] = B[j++];
		}
	}
	while (i <= mid) A[k++] = B[i++];
	while (j <= high) A[k++] = B[j++];
}

void Sort::BuildMaxHeap(int arr[], int size)
{
	for (int i = size / 2; i > 0; i--)
	{
		HeapAdjust(arr, i, size);
	}
}

void Sort::HeapAdjust(int arr[], int k, int len)
{
	// �����
	arr[0] = arr[k];
	for (int i = k * 2; i <= len; i *= 2)
	{
		if ((i + 1) < len && arr[i] < arr[i + 1])
		{
			i++;
		}
		if (arr[0] > arr[i])
			break;
		arr[k] = arr[i];
		k = i;
	}
	arr[k] = arr[0];
}

// ֱ�Ӳ�������
void Sort::InsertSort(int arr[], int size)
{
	int tem, i, j;
	for (i = 1; i < size; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			tem = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > tem; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tem;		//  j+1 һֱ�ǿյģ� j һֱ����Ƚϵ�Ԫ��
		}
	}
}

void Sort::BiInsertSort(int a[], int size)
{
	int tem, low, high,mid;
	for (int i = 1; i < size; i++)
	{
		low = 0;
		high = i - 1;
		tem = a[i];
		while (low <= high)				// �Ҳ���λ��
		{
			mid = (low + high) / 2;
			if (a[mid] > tem)			// ���>= �Ļ����Ͳ��ȶ���
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i-1; j >= low; j--)	// ����ƶ�
		{
			a[j + 1] = a[j];
		}
		a[low] = tem;
	}
}

void Sort::ShellSort(int a[], int n)
{
	int tem,d,i,j;
	for ( d = n / 2; d >= 1; d /= 2)		// ÿ������
	{
		for (i = d; i < n; i++)				// ͬ��������
		{
			if (a[i] < a[i - d])
			{
				tem = a[i];
				for (j = i - d; j >= 0&& a[j]> tem; j -= d)
				{
					a[j + d] = a[j];
				}
				a[j + d] = tem;
			}
		}
	}
}

void Sort::Bubble(int arr[], int size)
{
	int j;
	int flag = false;

	for (int i = 0; i < size - 1; i++)
	{
		flag = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] = arr[j] ^ arr[j + 1];
				arr[j + 1] = arr[j] ^ arr[j + 1];
				arr[j] = arr[j] ^ arr[j + 1];
				flag = true;
			}
		}
		if (!flag)
		{
			return;
		}
	}
}

int Sort::Partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	while (low < high)
	{
		while (low < high && pivot <= arr[high]) high--;
		arr[low] = arr[high];
		while (low < high && pivot >= arr[low]) low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void Sort::QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = Partition(arr, low, high);
		QuickSort(arr, low, mid - 1);		// ����
		QuickSort(arr, mid + 1, high);	// ����
	}
}

void Sort::SimpleSelectSort(int arr[], int size)
{
	//  ��������
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}

		}
		if (i != min)
		{
			Swap(arr[min], arr[i]);
		}
	}
}

void Sort::MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, high);
	}
}

/// <summary>
/// ������  ��Ϊ ��С�������� �ҽ���Ϊ�����
/// </summary>
/// <param name="arr: ">index = 0ʱ ӦΪ��Ԫ�� </param>
/// <param name="size: ">size Ϊ Ԫ�ظ���������index==0 </param>
void Sort::HeapSort(int arr[], int size)
{
	BuildMaxHeap(arr, size);
	for (int i = size; i > 1; i--)
	{
		Swap(arr[i], arr[1]);				//   ���һ��Ԫ�ر�Ϊ ��СԪ��  ���ص���  ���� >1
		HeapAdjust(arr, 1, i- 1);			// ÿ�λ�����һ��Ԫ�أ� ĩβԪ�ز�����
	}
}

void Sort::Swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}