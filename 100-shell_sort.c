#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * algorithm with Knuth sequence.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	/* Find the starting interval using Knuth sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Insertion sort for subarrays formed by the interval */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		/* Print the array after each interval reduction */
		print_array(array, size);

		/* Calculate the next interval using Knuth sequence */
		interval = (interval - 1) / 3;
	}
}
