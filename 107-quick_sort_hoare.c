#include "sort.h"
/**
*my_swap - positions of elements in an array
*@array: arrays
*@my_item_one: arrays elem
*@my_item_two: arrays elem
*/
void my_swap(int *array, ssize_t my_item_one, ssize_t my_item_two)
{
	int my_temp;

	my_temp = array[my_item_one];
	array[my_item_one] = array[my_item_two];
	array[my_item_two] = my_temp;
}
/**
 *my_hoare_partition - hoare sorting partition impl
 *@array: arrays
 *@my_first: my_first arrays elem
 *@my_last: my_last arrays elem
 *@size: siz arrays
 *Return: retur my_position of my_last elem sort
 */
int my_hoare_partition(int *array, int my_first, int my_last, int size)
{
	int my_current = my_first - 1, my_find = my_last + 1;
	int my_piv = array[my_last];

	while (1)
	{

		do {
			my_current++;
		} while (array[my_current] < my_piv);
		do {
			my_find--;
		} while (array[my_find] > my_piv);
		if (my_current >= my_find)
			return (my_current);
		my_swap(array, my_current, my_find);
		print_array(array, size);
	}
}
/**
 *my_QS - quick algo implem
 *@array: arrays
 *@my_first: my_first array elem
 *@my_last: my_last array elem
 *@size: arrays sizes
 */
void my_QS(int *array, ssize_t my_first, ssize_t my_last, int size)
{
	ssize_t my_position = 0;

	if (my_first < my_last)
	{
		my_position = my_hoare_partition(array, my_first, my_last, size);
		my_QS(array, my_first, my_position - 1, size);
		my_QS(array, my_position, my_last, size);
	}
}
/**
 *quick_sort_hoare - prep terrain to quick algo
 *@array: arrays
 *@size: arrays sizse
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	my_QS(array, 0, size - 1, size);
}
