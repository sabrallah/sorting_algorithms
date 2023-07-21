#include "sort.h"

/**
 * sa_swap - swap position values array
 * @array: array should changed
 * @sa_first: sa_first index
 * @sa_seconde: sa_seconde index
 *
 * Return: nothing_else_matter
 */
void sa_swap(int **array, int sa_first, int sa_seconde)
{
	int sa_holde;

	sa_holde = (*array)[sa_first];
	(*array)[sa_first] = (*array)[sa_seconde];
	(*array)[sa_seconde] = sa_holde;
}

/**
 * sa_max_heap - build heap from array
 * @array: array should changed to heap array
 * @sa_end_index: end index array partitioned
 * @sa_start_index: start a point index as array if sorted
 * @sa_size: size of array  unchanged
 *
 * Return: nothing_else_matter
 */
void sa_max_heap(int *array, int sa_end_index, int sa_start_index, int sa_size)
{
	int sa_large, sa_left, sa_right;

	sa_large = sa_start_index;
	sa_left = (sa_start_index * 2) + 1;
	sa_right = (sa_start_index * 2) + 2;

	if (sa_left < sa_end_index && array[sa_left] > array[sa_large])
		sa_large = sa_left;

	if (sa_right < sa_end_index && array[sa_right] > array[sa_large])
		sa_large = sa_right;

	if (sa_large != sa_start_index)
	{
		sa_swap(&array, sa_start_index, sa_large);
		print_array(array, sa_size);
		sa_max_heap(array, sa_end_index, sa_large, sa_size);
	}
}

/**
 * heap_sort - sort an array use Heap sort algorithm
 * @array: array be sorted
 * @size: size the array
 *
 * Return: nothing_else_matter
 */
void heap_sort(int *array, size_t size)
{
	int sa_start_index, y;

	if (!array || size < 2)
		return;

	sa_start_index = ((int)size - 1) / 2;


	for (y = sa_start_index; y >= 0; y--)
	{
		sa_max_heap(array, size, y, size);
	}


	for (y = size - 1; y > 0; y--)
	{
		sa_swap(&array, 0, y);
		print_array(array, size);
		sa_max_heap(array, y, 0, size);
	}
}
