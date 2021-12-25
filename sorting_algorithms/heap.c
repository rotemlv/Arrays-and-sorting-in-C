#include "headers.h"

void heapify_down_max_fast(int heap[], int i, int n)
{
	int largest = get_max_heap_child(heap, i, n);
	do
		swap(&heap[i], &heap[largest]);
	while ((largest = get_max_heap_child(heap, i = largest, n)) != i);
}

void heapify_down(int heap[], int i, int n, bool min_h)
{
	// if min, get minimum, else get max
	int((*cmp))(int*, int, int) = (min_h) ? get_min_heap_child : get_max_heap_child;
	int largest = cmp(heap, i, n);
	do
		swap(&heap[i], &heap[largest]);
	while ((largest = cmp(heap, i = largest, n)) != i);
}

void build_heap(int heap[], int n, bool min_h)
{
	// if min, build min heap, else build max
	int i;
	for (i = n >> 1; i >= 0; i--)
		heapify_down(heap, i, n, min_h);
}

void build_heap_pointers(int **heap, int n, bool min_h)
{
	// if min, build min heap, else build max
	int i;
	for (i = n >> 1; i >= 0; i--)
		heapify_down_pointers(heap, i, n, min_h);
}


void heapify_down_pointers(int **heap, int i, int n, bool min_h)
{
	// if min, get minimum, else get max
	int((*cmp))(int**, int, int) = (min_h) ? get_min_heap_child_p : get_max_heap_child_p;
	int largest = cmp(heap, i, n);
	do
		swap_p(&heap[i], &heap[largest]);
	while ((largest = cmp(heap, i = largest, n)) != i);
}

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

int get_max_heap_child_p(int **heap, int i, int n)
{
	int l = left(i), r = right(i);
	// select max:
	if (l < n && *(heap[l]) > *(heap[i]))
		i = l;
	if (r < n && *(heap[r]) > *(heap[i]))
		i = r;

	return i;
}

int get_min_heap_child_p(int **heap, int i, int n) {
	int l = left(i), r = right(i);
	// select min:
	if (l<n && *(heap[i]) > *(heap[l]))
		i = l;
	if (r<n && *(heap[i]) > *(heap[r]))
		i = r;
	return i;
}

int get_max_heap_child(int heap[], int i, int n)
{
	int l = left(i), r = right(i);
	// select max:
	if (l < n && heap[l] > heap[i])
		i = l;
	if (r < n && heap[r] > heap[i])
		i = r;

	return i;
}

int get_min_heap_child(int heap[], int i, int n) {
	int l = left(i), r = right(i);
	// select min:
	if (l<n && heap[i] > heap[l])
		i = l;
	if (r<n && heap[i] > heap[r])
		i = r;

	return i;
}

void heap_sort(int arr[], int size)
{
	// build the heap
	build_heap(arr, size, 0); // "0(n)"
	// grab and swap last element with first and heapify down
	int j = size - 1, n = size;
	while (j) // 0(n)
	{
		// swap last and first
		swap(&arr[j--], &arr[0]);
		heapify_down_max_fast(arr, 0, --n); // for the first n/2 elements it can be considered as 0(1)
	}
}

// An attempt to print a short heap nicely, could be used for beginner debug
void print_heap(int* arr, int size)
{
	int i = 0, t = 2, initial_index = 0;
	int t_power, height = (int)log2(size); // set height, decrement each iteration
	for (t_power = pow(t, i); t_power <= size; t_power = pow(t, i))
	{
		//printf("init:%d, pow:%d\n", initial_index, t_power);
		int j; // actual index
		// pad left:
		for (int k = 0; k < 5 * height; k++)
		{
			printf(" ");
		}
		for (j = initial_index; j < t_power + initial_index && j < size; j++)
		{
			printf("%d ", arr[j]);
			for (int k = 0; k < (int) (1.4 * height * sqrt(height)); k++)
			{
				printf(" "); // pad between each element
			}
		}
		printf("\n\n");
		initial_index += t_power;
		i++;
		height--;
	}
}
