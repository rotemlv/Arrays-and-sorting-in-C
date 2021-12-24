#include "headers.h"

int partition_around_piv(int arr[], int st, int en, int piv) // works though
{
	while (st <= en)
	{
		while (st < en && arr[st] < piv)
			st++;
		while (arr[en] > piv)
			en--;
		if (arr[st] == arr[en]) // the only way this happens is if these are idential to pivot
			st++;
		else if (st < en)
			swap(&arr[st], &arr[en]);
	}
	return en;
}

void insertion_sort_partial(int arr[], int start, int end) {
		int i = start + 1;
		for (; i <= end; i++) {
			int key = arr[i], j = i - 1;
			while (j >= start && key < arr[j]) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	
}

void sort_partial_arr_groups(int arr[], int st, int en, int group_size)
{
	int i, min_edge;
	for (i = st; i <= en; i += group_size)
	{
		min_edge = min(i + group_size - 1, en);
		insertion_sort_partial(arr, i, min_edge);
	}
}

int* array_of_medians_partial(int arr[], int start, int end, int group_size, int* median_size)
{
	// input is an array sorted in groups of group_size (should be 5)
	// output is an array of pivots of each sorted sub-array
	double input_size = end - start + 1;
	input_size /= (double)group_size;
	int total_groups = (int)ceil(input_size);
	int* medians = malloc(total_groups * sizeof * medians);
	if (medians != NULL) {
		// insert pivot for each group:
		int i, j = 0;
		for (i = 0; i < total_groups; i++)
		{
			j = min(i * 5 + 4, end); // j is the rightmost index of sub array
			//printf("indices: [(%d + (5 * %d)) / 2] is %d, array is %d\n",j,i, (j + (5 * i)) / 2,arr[(j + (5 * i)) / 2]);
			medians[i] = arr[(j + (5 * i)) / 2]; // we add the middle
		}
		//for (i = 0; i < size && j<total_groups; i += group_size)
		*median_size = total_groups;
	}
	return medians;
}

int choose_pivot_new(int arr[], int st, int en)
{
	// base case: if array size is less than 10, sort it and return arr[size/2]
	if (en - st + 1 < 10)
	{
		insertion_sort_partial(arr, st, en);
		return arr[st + (en - st) / 2];
	}
	// else, use the median of medians and sort the ting:
	sort_partial_arr_groups(arr, st, en, 5);
	int* tmp, tmpsize = 0;
	tmp = array_of_medians_partial(arr, st, en, 5, &tmpsize);
	int x = choose_pivot_new(tmp, 0, tmpsize - 1);
	free(tmp);
	return x; // this is the pivot
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true)
	{
		// Find leftmost element greater
		// than or equal to pivot
		do {
			i++;
		} while (arr[i] < pivot);

		// Find rightmost element smaller
		// than or equal to pivot
		do {
			j--;
		} while (arr[j] > pivot);

		// If two pointers met.
		if (i >= j)
			return j;

		// swap(arr[i], arr[j]);
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int selectFF(int *arr, int s, int e, int k) {

	if (e - s + 1 <= 5) {

		//If the difference was 1, return s only
		int end;
		end = e;
		end = end + 1;
		int diff = end - s;
		if (diff == 1)
		{
			return s;
		}
		else {
			insertion_sort_partial(arr, s, e);
			return s + k;
		}
	}

	// if array is bigger
	// we partition the array in subarrays of size 5
	// and total number of partitions is ceiling of division by 5

	float maxIter = ((float)(e + 1) / 5);

	maxIter = ceil(maxIter);


	//Instead of finding the median from 3rd position, if the difference is even subtract 1
	//If the difference is odd divide by 2
	for (int i = 0; i < maxIter; i++) {
		//cout << endl;

		int left = 5 * i;

		int right = left + 4;

		if (right > e) {

			right = e;
		}

		int difference = right - left;
		difference++;

		if (difference % 2 == 0)
		{
			difference = (difference / 2) - 1;

		}
		else
		{
			difference = difference / 2;

		}


		int median = selectFF(arr, left, right, difference);

		swap(&arr[median], &arr[i]);

	}

	int selector = (e + 1) / 10;

	return selectFF(arr, 0, maxIter - 1, selector);

}
int select(int* a, int s, int e, int k) {
	// if the partition length is less than or equal to 5
	// we can sort and find the kth element of it
	// this way we can find the median of n/5 partitions
	if (e - s + 1 <= 5) {
		insertion_sort_partial(a, s, e);
		return s + k - 1;
	}

	// if array is bigger 
	// we partition the array in subarrays of size 5
	// no. of partitions = n/5 = (e+1)/5
	// iterate through each partition
	// and recursively calculate the median of all of them
	// and keep putting the medians in the starting of the array
	for (int i = 0; i < (e + 1) / 5; i++) {
		int left = 5 * i;
		int right = left + 4;
		if (right > e) right = e;
		int median = select(a, 5 * i, 5 * i + 4, 3);
		swap(&a[median], &a[i]);
	}

	// now we have array 
	// a[0] = median of 1st 5 sized partition
	// a[1] = median of 2nd 5 sized partition
	// and so on till n/5
	// to find out the median of these n/5 medians
	// we need to select the n/10th element of this set (i.e. middle of it)
	return select(a, 0, (e + 1) / 5, (e + 1) / 10);
}
void quickSortNew(int arr[], int st, int en)
{
	if (st < en)
	{
		// find the pivot (Select)
		int p = selectFF(arr, st, en,(en+st)/2); // find pivot element in array[st..en+1]
		// set p to st:
		swap(&arr[p], &arr[st]);
		int q = partition(arr, st, en); // partition around element, return index
		printf("arr[q] == p: %d\n", arr[q] == p);
		quickSortNew(arr, st, q);
		quickSortNew(arr, q + 1, en);
	}
}
