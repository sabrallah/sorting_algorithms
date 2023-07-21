#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int find_max(int *array, size_t size);

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;
	int *output;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int count[10] = {0};

		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size; i > 0; i--)
		{
			output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
			count[(array[i - 1] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(output);
}

/**
 * find_max - Finds the maximum value in an array of integers.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
