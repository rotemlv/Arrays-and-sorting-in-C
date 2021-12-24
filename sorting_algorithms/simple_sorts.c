#include "simple_sorts.h"

void insertion_sort(int arr[], int size) {
	int i = 1;
	for (; i < size; i++) {
		int key = arr[i], j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void selection_sort(int arr[], int size) {
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void bubble_sort(int arr[], int n) {
	int j = 0, i;
	for (i = 0; i < n; i++) // for each index, bubble it to the top
		for (j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void bubble_sort_optimized(int arr[], int n) {
	int i, j = 0, swapped = 1, temp;
	while (swapped) {
		swapped = 0;
		for (i = 0; i < n - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
		}
		j++;
	}
}
