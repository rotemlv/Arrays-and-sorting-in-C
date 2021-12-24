#include "headers.h"


#define _TEST_QUICKS 1
#define _TEST_HEAPS 1
#define _TEST_SHELLS 1
#define _PRINT_ARRAY 0

#define N 1000000

int main()
{
	srand((unsigned int)time(NULL));
	int *arr = malloc(N * sizeof * arr);


	//print_array(arr, N, print_integer_array);
	time_t t1, t2;
	printf("testing sorts for N = %d\n", N);
	if (_TEST_QUICKS) { 
		random_array(arr, N, 0, 2 * N);
		t1 = clock();
		quick_sort(arr, N); 
		t2 = clock();
		printf("array sorted: %d\n", verify_sorted(arr, N));
		printf("time algorithm %s took: %d (ms)\n", "quicksort", (int)t2 - (int)t1);
	}
	if (_TEST_HEAPS) {
		random_array(arr, N, 0, 2 * N);
		t1 = clock();
		heap_sort(arr, N);
		t2 = clock();
		printf("array sorted: %d\n", verify_sorted(arr, N));
		printf("time algorithm %s took: %d (ms)\n", "heapsort", (int)t2 - (int)t1);
	}
	if (_TEST_SHELLS) {
		random_array(arr, N, 0, 2 * N);
		t1 = clock();
		shell_sort(arr, N);
		t2 = clock();
		printf("array sorted: %d\n", verify_sorted(arr, N));
		printf("time algorithm %s took: %d (ms)\n", "shellsort", (int)t2 - (int)t1);
	}

	if(_PRINT_ARRAY)
	print_array(arr, N, print_integer_array);

	//printf("array sorted: %d", verify_sorted(arr, N));

	// freedom stuff
	free(arr);

	return EXIT_SUCCESS;
}

