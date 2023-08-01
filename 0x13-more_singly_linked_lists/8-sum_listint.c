#include "lists.h"

/**
 * sum_listint - Computes sum of all the data in a list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The total of all data in the list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0; /* Variable to store the sum */
	listint_t *current_node = head; /* Pointer to traverse list */

	/* Traverse the linked list to calculate */
	while (current_node)
	{
		sum += current_node->n; /* Add the current node*/
		current_node = current_node->next; /* Move to the next node */
	}

	return (sum); /* Return the resulting sum */
}
