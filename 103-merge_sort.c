#include "sort.h"

/**
 * my_print_parse - prints array value
 *
 * @array: array printed
 * @my_text: my_text printed values
 * @my_low: low boun
 * @my_hight: up boun
 */
void my_print_parse(int *array, const char *my_text,
		size_t my_low, size_t my_hight)
{
	size_t y;
	char *my_separator = "";

	printf("[%s]: ", my_text);
	for (y = my_low; y <= my_hight; y++)
	{
		printf("%s%d", my_separator, array[y]);
		my_separator = ", ";
	}
	printf("\n");
}
/**
 * my_join_parse - join value sort in the array
 * parsed
 *
 * @arr: array sorted
 * @my_low: start index array passe
 * @my_hight: end index array passed
 * @my_mid: mid split array
 * @my_copy: array sorte values
 */
void my_join_parse(int *arr, size_t my_low, size_t my_hight,
		size_t my_mid, int *my_copy)
{
	size_t my_hstart = my_mid + 1, my_newIndex, my_lstart = my_low, y;

	printf("Merging...\n");
	my_print_parse(arr, "left", my_low, my_mid);
	my_print_parse(arr, "right", my_mid + 1, my_hight);

	for (my_newIndex = my_low; my_newIndex <= my_hight; my_newIndex++)
	{
		if ((my_lstart <= my_mid && arr[my_lstart] <= arr[my_hstart]) ||
				my_hstart > my_hight)
			my_copy[my_newIndex] = arr[my_lstart++];
		else
			my_copy[my_newIndex] = arr[my_hstart++];
	}

	for (y = my_low; y <= my_hight; y++)
		arr[y] = my_copy[y];

	my_print_parse(arr, "Done", my_low, my_hight);
}

/**
 * my_parser - recur merge sort et sort the
 * giv array
 *
 * @array: array sorted
 * @my_lb: low boun
 * @my_ub: up boun
 * @my_copy: array store values
 */
void my_parser(int *array, size_t my_lb, size_t my_ub, int *my_copy)
{
	size_t my_mid;

	if (my_lb < my_ub)
	{
		my_mid = (my_ub + my_lb - 1) / 2;

		my_parser(array, my_lb, my_mid, my_copy);
		my_parser(array, my_mid + 1, my_ub, my_copy);

		my_join_parse(array, my_lb, my_ub, my_mid, my_copy);
	}
}

/**
 * merge_sort - appli the merge sort
 * algorithm sort an array integers
 *
 * @array: array sorted
 * @size: size array
 */
void merge_sort(int *array, size_t size)
{
	int *my_clone;

	if (!array || size < 2)
		return;

	my_clone = malloc(sizeof(int) * size);
	if (!my_clone)
		return;

	my_parser(array, 0, size - 1, my_clone);
	free(my_clone);
}
