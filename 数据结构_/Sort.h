#pragma once


class Sort {

public:
	void InsertSort(int arr[], int size);
	void BiInsertSort(int arr[], int size);
	void ShellSort(int a[], int n);
	void Bubble(int arr[], int size);
	void QuickSort(int arr[],int low, int high);
	void SimpleSelectSort(int arr[], int size);
	void MergeSort(int A[], int low, int high);
	void HeapSort(int arr[], int size);
private:
	int Partition(int arr[], int low, int high);
	void Merge(int A[], int low, int high);
	void BuildMaxHeap(int arr[], int size);
	void HeapAdjust(int arr[], int k, int len);
	void Swap(int& a, int& b);
};