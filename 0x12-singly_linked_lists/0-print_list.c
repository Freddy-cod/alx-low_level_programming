#include <stdio.h>
#include "lists.h"

/**
 * print_list - returns  elements of a list_t list.
 * @h: Its a Pointer to the list_t list to print.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0; /* Initialize the node count */

	while (h)
	{
		if (!h->str) /* If the string is NULL, print [0] (nil) */
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str); /* Print the length and the string */
		h = h->next; /* Move to the next node */
		count++; /* Increment the node count */
	}

	return (count); /* Return the total number of nodes */
}

