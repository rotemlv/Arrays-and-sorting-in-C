#include "headers.h"

void shell_sort(int arr[], int size) {
	int gap = size / 2, i, key, j;
	while (gap) {
		for (i = 1; i < size; i++) {
			key = arr[i], j = i - gap;
			while (j >= 0 && key < arr[j]) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = key;
		}
		gap /= 2;
	}
}

void wrapped_quick_sort(int* arr, int first, int last)
{
	int i, j, piv;
	if (first >= last)
		return;
	piv = i = first;
	j = last;
	while (i < j)
	{
		while (i < last && arr[i] <= arr[piv]) i++;
		while (arr[j] > arr[piv]) j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[piv], &arr[j]);
	wrapped_quick_sort(arr, first, j - 1);
	wrapped_quick_sort(arr, j + 1, last);
}

void quick_sort(int* arr, int size) {
	wrapped_quick_sort(arr, 0, size - 1);
}