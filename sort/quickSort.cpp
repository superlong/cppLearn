/*
 * quickSort.cpp
 *
 *  Created on: 2016年7月20日
 *      Author: weilongy
 */

#include <iostream>

using namespace std;


int Partition1(int a[], int low, int high)
{
	int i = low;
	int j = high + 1;
	int pivot = a[low];

	while (1) {
		while (a[++i] < pivot && i < high);
		while (a[--j] > pivot && j > low);
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[low], a[j]);
	return j;
}


void Quick(int a[], int low, int high)
{
	if (low >= high) return;
	int index = Partition1(a, low, high);
	Quick(a, low, index - 1);
	Quick(a, index + 1, high);
}

int main()
{
	int a[] = {1,5,7,3,2,5,7,90,5,3,232,5,68,9};
	Quick(a, 0, sizeof(a)/sizeof(int) - 1);

	for (int i =0; i < sizeof(a)/sizeof(int); i++) {
		cout<<a[i]<<" ";
	}

}
