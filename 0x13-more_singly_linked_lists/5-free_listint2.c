#include "lists.h"

/**
 * free_listint2 - Frees a linked list,sets pointer to NULL.
 * @head: Pointer to the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	/* Check if list is empty or  NULL. */
	if (head == NULL || *head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next; /* Store the next node */

		free(*head); /* Free the current node */
		*head = temp; /* Move to the next node */
	}

	*head = NULL; /* Set the head to NULL */
}
