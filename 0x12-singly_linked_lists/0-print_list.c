#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the list_t list.
 *
 * Description: This function prints all the elements of a singly linked list.
 *              If the string of a node is NULL, it prints [0] (nil).
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	unsigned int node_count = 0; /* Initialize the node count */

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n"); /* If the string is NULL, print [0] (nil) */
		else
			printf("[%d] %s\n", h->len, h->str); /* Print the length and the string */
		h = h->next; /* Move to the next node */
		node_count++; /* Increment the node count */
	}

	return (node_count); /* Return the total number of nodes */
}

