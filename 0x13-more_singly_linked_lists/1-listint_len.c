#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked list.
 * @h: Pointer to the head of the linked list (of type listint_t).
 *
 * Return: Number of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0; /* Initialize counter for the number of nodes */

	/* Traverse the linked list and count the nodes */
	while (h)
	{
		num++; /* Increment the counter */
		h = h->next; /* Move to the next node */
	}

	return (num); /* Return the total number of nodes */
}

