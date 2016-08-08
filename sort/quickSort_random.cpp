/*
 * quickSort_random.cpp
 *
 *  Created on: 2016年6月16日
 *      Author: weilongy
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int RandomInRange(int left, int right)
{
	srand(time(NULL));
	return left + rand()%(right - left + 1);
}


void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


int Partition(int a[], int low, int high)
{
	int small = low - 1;

	int pivot = RandomInRange(low, high);
	swap(a[pivot], a[high]);

	for (int index = low; index < high; index++) {
		if (a[index] < a[high]) {
			small++;
			if (small != index) {
				swap(a[small], a[index]);
			}
		}
	}
	++small;
	swap(a[small], a[high]);
	return small;
}

void QuickSort(int a[], int start, int end)
{
	if (start >= end)
		return;
	int p = Partition(a, start, end);
	if (start < p)
		QuickSort(a, start, p - 1);
	if (p < end)
		QuickSort(a, p + 1, end);
}


//int main()
//{
//	int a[] = {43,21,46,4,56,87,43,21,6,9,44};
//	QuickSort(a, 0, sizeof(a)/sizeof(int) - 1);
//	Print(a, sizeof(a)/sizeof(int));
//}



