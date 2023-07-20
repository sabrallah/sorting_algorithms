#include "sort.h"

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
	int pivot = array[high];
	int i = low;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
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
 * sort algorithm with the Lomuto partition scheme
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
