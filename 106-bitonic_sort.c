#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_compare - Auxiliary function for bitonic sort.
 * @up: Direction of sorting.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void bitonic_compare(int up, int *array, size_t size)
{
	size_t dist, i;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
			swap(&array[i], &array[i + dist]);
	}
}

/**
 * bitonic_merge - Merge function for bitonic sort.
 * @up: Direction of sorting.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void bitonic_merge(int up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + size / 2, size / 2);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	printf("Merging [%lu/%lu] (UP):\n", (unsigned long)size, (unsigned long)size);
	print_array(array, size);
	bitonic_merge(1, array, size);
	printf("Result [%lu/%lu] (UP):\n", (unsigned long)size, (unsigned long)size);
	print_array(array, size);
}
