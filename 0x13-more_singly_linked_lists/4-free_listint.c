#include "lists.h"

/**
 * free_listint - This frees a linked list.
 * @head: Pointer to the listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
	listint_t *current_node; /* Pointer to the current node to free */

	while (head)
	{
		current_node = head; /* Store cur node in a temp variable */
		head = head->next; /* Move next node before freeing */
		free(current_node); /* Free the current node */
	}
}

