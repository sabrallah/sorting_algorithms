#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Counting sort algorithm. It assumes that the input array will
 * contain only numbers >= 0. The function prints the counting array once it
 * is set up. The counting array is of size k + 1 where k is the largest number
 * in the input array. This version of the function takes into account the
 * minimum value in the input array to reduce the size of the counting array
 * and potentially improve the efficiency of the algorithm.
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max = 0, min = array[0];
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	count = malloc(sizeof(int) * (max - min + 1));
	output = malloc(sizeof(int) * size);

	for (i = 0; i <= max - min; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i] - min] += 1;

	for (i = 1; i <= max - min; i++)
		count[i] += count[i - 1];

	print_array(count, max - min + 1);

	for (j = size - 1; j >= 0; j--)
	{
		output[count[array[j] - min] - 1] = array[j];
		count[array[j] - min] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
