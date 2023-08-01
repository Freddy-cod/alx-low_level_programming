#include "lists.h"

/**
 * print_listint -Returns or Prints all the elements of a linked list.
 * @h: Pointer to the head of the linked list (of type listint_t).
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0; /* Counter to keep track of the number of nodes */

	/* Traverse the linked list while h points to a non-NULL node */
	while (h)
	{
		printf("%d\n", h->n); /* Print value stored in the current node */
		num++; /* Increment the node counter */
		h = h->next; /* Move to the next node */
	}

	return (num); /* Return the total number of nodes printed */
}

