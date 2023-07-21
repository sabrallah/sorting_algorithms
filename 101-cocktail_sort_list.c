#include "sort.h"

/**
 * my_nod_swapi - my_swaping nodes in list
 *
 * @list: one node list doubly linked
 * @one: addres of one node
 * @two: addres of two node
 */
void my_nod_swapi(listint_t **list, listint_t *one, listint_t *two)
{
	if (!one->prev)
		*list = two;
	else
		one->prev->next = two;

	two->prev = one->prev;

	if (two->next)
		two->next->prev = one;


	one->prev = two;
	one->next = two->next;
	two->next = one;
}

/**
 * cocktail_sort_list - cocktail sort algorithm applications
 * sort numbers
 *
 * @list: one node list of doubly linked
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *avenir;
	int my_swaping = 1;


	if (!list || !(*list) || !(*list)->next)
		return;

	avenir = *list;
	while (my_swaping)
	{
		my_swaping = 0;
		while (avenir->next)
		{
			if (avenir->n > avenir->next->n)
			{
				my_nod_swapi(list, avenir, avenir->next);
				print_list(*list);
				my_swaping = 1;
				continue;
			}
			avenir = avenir->next;
		}

		if (!my_swaping)
			break;

		my_swaping = 0;
		while (avenir->prev)
		{
			if (avenir->n < avenir->prev->n)
			{
				my_nod_swapi(list, avenir->prev, avenir);
				print_list(*list);
				my_swaping = 1;
				continue;
			}
			avenir = avenir->prev;
		}
	}
}
