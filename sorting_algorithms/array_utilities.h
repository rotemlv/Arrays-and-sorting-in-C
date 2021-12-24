#ifndef _ARR_UTILS
#define _ARR_UTILS
//#include "heap.h"
#include "headers.h"

#define DOUBLE_COMPARISON_EPSILON 1e-11 // used for declaring two variables identical if diff<epsilon

void swap(int* a, int* b);
void swap_p(int** a, int** b);


// print array
void print_array(void* arr, size_t size, void (*print_func)(void*,size_t)); // print any array

int randint(int s, int e);

// randomize arrays
void random_array(int* arr, size_t size, int random_min, int random_max); // integer array
void random_dbl_array(double* arr, size_t size); // double arr
void random_float_array(float* arr, size_t size); // float arr

void print_integer_array(int* arr, size_t size); 
void print_float_array(float* arr, size_t size); 
void print_double_array(double* arr, size_t size);
void print_char_array(char* arr, size_t size);
void print_bool_array(bool* arr, size_t size);

bool compare_arrays(void* arr1, void* arr2, size_t size, bool (*cmp)(void*, void*, size_t));

bool cmp_int_arrs(int *a1, int *a2, size_t size);
bool cmp_double_arrs(double *a1, double *a2, size_t size);

bool verify_sorted(int* arr, size_t size); // generic verification

#endif