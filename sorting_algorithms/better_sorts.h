#ifndef _BETTER_SORTS
#define _BETTER_SORTS

#include "headers.h"


void shell_sort(int arr[], int size);

// this actually handles the sort
void wrapped_quick_sort(int* arr, int first, int last);

// user friendly wrapper that recieves array and its size, calls quicksort with proper args
void quick_sort(int* arr,int size);

#endif