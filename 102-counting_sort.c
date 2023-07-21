#include "sort.h"


/**
 * start_initi - init array 0
 *
 * @array: should init array
 * @size: array size
 */
void start_initi(int *array, int size)
{
	int sy;

	for (sy = 0; sy < size; sy++)
		array[sy] = 0;
}


/**
 * avoir_maxi - avoir maximaum valeur
 *
 * @array: plafond value from of array
 * @size: array size
 *
 * Return: array max value
 */
int avoir_maxi(int *array, size_t size)
{
	int plafond;
	size_t sy;

	if (size < 2)
		return (0);

	plafond = array[0];

	for (sy = 1; sy < size; sy++)
	{
		if (plafond < array[sy])
			plafond = array[sy];
	}

	return (plafond);
}


/**
 * counting_sort - sorts array of counting
 * sort algo
 *
 * @array: init arrays
 * @size: the array size
 */
void counting_sort(int *array, size_t size)
{
	int y = avoir_maxi(array, size), s, *place, *addplace, *my_sorted;
	size_t sy;

	if (y == 0)
		return;

	place = malloc(sizeof(int) * (y + 1));
	if (!place)
		return;
	start_initi(place, y + 1);

	for (sy = 0; sy < size; sy++)
		place[array[sy]] += 1;

	addplace = malloc(sizeof(int) * (y + 1));
	if (!addplace)
		return;
	start_initi(addplace, y + 1);
	addplace[0] = place[0];

	for (s = 1; s < (y + 1); s++)
		addplace[s] = place[s] + addplace[s - 1];

	free(place), print_array(addplace, y + 1);

	my_sorted = malloc(sizeof(int) * size);
	if (!my_sorted)
		return;
	start_initi(my_sorted, size);

	for (sy = 0; sy < size; sy++)
	{
		addplace[array[sy]] -= 1;
		my_sorted[addplace[array[sy]]] = array[sy];
	}
	free(addplace);

	for (sy = 0; sy < size; sy++)
		array[sy] = my_sorted[sy];
	free(my_sorted);
}
