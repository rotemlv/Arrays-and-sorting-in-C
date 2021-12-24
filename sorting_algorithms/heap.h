#ifndef _HEAP
#define _HEAP
#include "headers.h"

void print_heap(int* arr, int size);

void heap_sort(int arr[], int size);
int parent(int);
int left(int);
int right(int);

void heapify_down_max_fast(int heap[], int i, int n);

void heapify_down(int heap[], int i, int n, bool min_h);
void build_heap(int heap[], int n, bool min_h);
int get_max_heap_child(int heap[], int i, int n);
int get_min_heap_child(int heap[], int i, int n);

/// <summary>
/// Pointers based heap building utilities
/// Assumes each element in heap is the head of an array
/// Sizes of each array are kept by user, mind these
int get_min_heap_child_p(int** heap, int i, int n);
int get_max_heap_child_p(int** heap, int i, int n);
void heapify_down_pointers(int** heap, int i, int n, bool min_h);
void build_heap_pointers(int** heap, int n, bool min_h);

#endif