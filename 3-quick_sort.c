#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @array: array containing the integers
 * @i: index of the first integer
 * @j: index of the second integer
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}

/**
 * median_of_three - chooses the median of the first, middle, and last elements
 * of a partition as the pivot
 * @array: array containing the partition
 * @low: lowest index of the partition
 * @high: highest index of the partition
 *
 * Return: index of the pivot
 */
int median_of_three(int *array, int low, int high)
{
	int mid = (low + high) / 2;

	if (array[low] > array[mid])
		swap(array, low, mid);
	if (array[low] > array[high])
		swap(array, low, high);
	if (array[mid] > array[high])
		swap(array, mid, high);

	return (mid);
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: array to partition
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot_index = median_of_three(array, low, high);
	int pivot = array[pivot_index];
	int i = low;
	int j;

	swap(array, pivot_index, high);
	print_array(array, size);

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(array, i, high);
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_helper - recursive helper function for quick_sort
 * @array: array to sort
 * @low: lowest index of the current partition
 * @high: highest index of the current partition
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm with the Lomuto partition scheme and median-of-three method
 * for choosing the pivot
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
