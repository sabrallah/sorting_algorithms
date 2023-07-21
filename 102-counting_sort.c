#include "sort.h"

/**
 * my_arr_init - init by 0 array
 *
 * @array: init be initialased
 * @size: size array
 */
void my_arr_init(int *array, int size)
{
	int sa;

	for (sa = 0; sa < size; sa++)
		array[sa] = 0;
}

/**
 * my_getmax - get max value in array
 *
 * @array: array my_max value from
 * @size: size the array
 *
 * Return: max value in array
 */
int my_getmax(int *array, size_t size)
{
	int my_max;
	size_t sa;

	if (size < 2)
		return (0);

	my_max = array[0];

	for (sa = 1; sa < size; sa++)
	{
		if (my_max < array[sa])
			my_max = array[sa];
	}

	return (my_max);
}

/**
 * counting_sort - sort array counting
 * sor algo
 *
 * @array: init arrays
 * @size: size arrays
 */
void counting_sort(int *array, size_t size)
{
	int y = my_getmax(array, size), j, *my_position, *my_sumposition, *my_sorted;
	size_t sa;

	if (y == 0)
		return;

	my_position = malloc(sizeof(int) * (y + 1));
	if (!my_position)
		return;
	my_arr_init(my_position, y + 1);

	for (sa = 0; sa < size; sa++)
		my_position[array[sa]] += 1;

	my_sumposition = malloc(sizeof(int) * (y + 1));
	if (!my_sumposition)
		return;
	my_arr_init(my_sumposition, y + 1);
	my_sumposition[0] = my_position[0];

	for (j = 1; j < (y + 1); j++)
		my_sumposition[j] = my_position[j] + my_sumposition[j - 1];

	free(my_position), print_array(my_sumposition, y + 1);

	my_sorted = malloc(sizeof(int) * size);
	if (!my_sorted)
		return;
	my_arr_init(my_sorted, size);

	for (sa = 0; sa < size; sa++)
	{
		my_sumposition[array[sa]] -= 1;
		my_sorted[my_sumposition[array[sa]]] = array[sa];
	}
	free(my_sumposition);

	for (sa = 0; sa < size; sa++)
		array[sa] = my_sorted[sa];
	free(my_sorted);
}
