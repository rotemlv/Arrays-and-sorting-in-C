#ifndef _QUICKSORT
#define _QUICKSORT
#include "headers.h"
int choose_pivot_new(int arr[], int st, int en);
int partition_around_piv(int arr[], int st, int en, int piv); // works though
void sort_partial_arr_groups(int arr[], int st, int en, int group_size);
int* array_of_medians_partial(int arr[], int start, int end, int group_size, int* median_size);
void quickSortNew(int arr[], int st, int en);
void insertion_sort_partial(int arr[], int start, int end);

#endif