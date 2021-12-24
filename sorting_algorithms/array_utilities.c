#include "headers.h"


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap_p(int** a, int** b)
{
	int* t = *a;
	*a = *b;
	*b = t;
}

bool verify_sorted(int* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size - 1 && arr[i] <= arr[i + 1]; i++);
	return i + 1 == size;
}

void print_array(void* arr, size_t size, void (*print_func)(void*, size_t))
{
	print_func(arr, size);
}

int randint(int s, int e)
{
	return (rand() % (e - s + (s>0))) + s;
}

void random_array(int* arr, size_t size, int random_min, int random_max) // integer array
{
	size_t i;
	time_t t;
	time(&t);
	MTRand r = seedRand(t);
	for (i = 0; i < size; i++)
		arr[i] = (genRandLong(&r)%(random_max - random_min + 1)) + random_min;
}


void random_dbl_array(double* arr, size_t size)
{
	size_t i;
	time_t t;
	time(&t);
	MTRand r = seedRand(t);
	for (i = 0; i < size; i++) {
		arr[i] = genRand(&r); 
	}
}
void random_float_array(float* arr, size_t size)
{
	size_t i;
	time_t t;
	time(&t);
	MTRand r = seedRand(t);
	for (i = 0; i < size; i++) {
		arr[i] = (float)genRand(&r); 
	}
}


void print_integer_array(int* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
 		printf("%d ", arr[i]);
	printf("\n");
}

void print_float_array(float* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		printf("%g ", arr[i]);
	printf("\n");
}

void print_double_array(double* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		printf("%g ", arr[i]);
	printf("\n");
}

void print_char_array(char* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		printf("%c ", arr[i]);
	printf("\n");
}
void print_bool_array(bool* arr, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// returns true if both arrays have identical elements, else false
bool compare_arrays(void* arr1, void* arr2, size_t size, bool (*cmp)(void*, void*, size_t))
{
	return cmp(arr1, arr2, size);
}

bool cmp_int_arrs(int* a1, int* a2, size_t size)
{
	size_t i;
	int offset = 0;
	for (i = 0; i < size && !offset; i++)
		offset = a1[i] - a2[i];
	return offset == 0;
}

bool cmp_double_arrs(double* a1, double* a2, size_t size)
{
	// if elements maintain |e1-e2| < epsilon, returns true (arrays are identical), else false
	size_t i;
	double offset = 0.0;
	for (i = 0; i < size && offset < DOUBLE_COMPARISON_EPSILON; i++)
		offset = fabs((a1[i] - a2[i]));
	return offset < DOUBLE_COMPARISON_EPSILON;
}
