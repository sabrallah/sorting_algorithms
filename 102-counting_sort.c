#include "sort.h"



/**
 * counting_sort - sort array sort algorithm
 * @array: array that given
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t s;
	int y;
	int *my_counter, *my_sorted;

	if (size < 2 || !array)
		return;
	for (s = 1, y = array[0]; s < size; s++)
		if (array[s] > y)
			y = array[s];

	my_counter = malloc(sizeof(size_t) * (y + 1));
	if (!my_counter)
		return;
	for (s = 0; (int)s < y + 1; s++)
		my_counter[s] = 0;
	for (s = 0; s < size; s++)
		my_counter[array[s]] += 1;
	for (s = 1; (int)s <= y; s++)
		my_counter[s] += my_counter[s - 1];
	print_array(my_counter, y + 1);
	my_sorted = malloc(sizeof(int) * (size));
	if (!my_sorted)
	{
		free(my_counter);
		return;
	}
	for (s = 0; s < size; s++)
	{
		my_sorted[my_counter[array[s]] - 1] = array[s];
		my_counter[array[s]] -= 1;
	}
	for (s = 0; s < size; s++)
		array[s] = my_sorted[s];
	free(my_sorted);
	free(my_counter);
}
