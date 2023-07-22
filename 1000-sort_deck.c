#include "deck.h"


/**
 * sort_deck - sorts of card
 * @deck: sort doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *my_curr;
	size_t len;
	deck_node_t *my_un, *my_deux, *my_troi, *my_quatre;

	len = my_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	my_curr = *deck;
	while (my_curr)
	{
		if (my_curr->prev && my_value_card(my_curr) < my_value_card(my_curr->prev))
		{
			my_un = my_curr->prev->prev;
			my_deux = my_curr->prev;
			my_troi = my_curr;
			my_quatre = my_curr->next;

			my_deux->next = my_quatre;
			if (my_quatre)
				my_quatre->prev = my_deux;
			my_troi->next = my_deux;
			my_troi->prev = my_un;
			if (my_un)
				my_un->next = my_troi;
			else
				*deck = my_troi;
			my_deux->prev = my_troi;
			my_curr = *deck;
			continue;
		}
		else
			my_curr = my_curr->next;
	}
}

/**
 * my_value_card - value of a card returned
 * @node: card deck
 *
 * Return: between 1 and 52
 */
int my_value_card(deck_node_t *node)
{
	char *my_val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *my_kind[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int y, my_kind_val = 0;

	for (y = 1; y <= 13; y++)
	{
		if (!my_strcamp(node->card->value, my_val[y - 1]))
			my_kind_val = y;
	}

	for (y = 1; y <= 4; y++)
	{
		if (!my_strcamp(my_kind[node->card->kind], my_kind[y - 1]))
			my_kind_val = my_kind_val + (13 * y);
	}

	return (my_kind_val);
}


/**
 * my_strcamp - comparable my_deux string
 * @my_1: first string for compare
 * @my_2: second string for compare
 *
 * Return: lower than 0 if my_1 is less than my_2, 0 if they are equal,
 * higher than 0 if my_1 is great than my_2
 */
int my_strcamp(const char *my_1, const char *my_2)
{
	while (*my_1 == *my_2)
	{
		if (*my_1 == '\0')
		{
			return (0);
		}
		my_1++;
		my_2++;
	}
	return (*my_1 - *my_2);
}

/**
 * my_len_deck - function length of list
 * @list: heads list
 *
 * Return: len
 */
size_t my_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
