#include "lists.h"

/**
 * reverse_listint - Reverses a list linked in place.
 * @head: Pointer to the pointer of the first node in the list.
 *
 * Return: Pointer to the first node in the new reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL; /* Pointer to store the previous node */
	listint_t *next_node = NULL; /* Pointer to store the next node */

	while (*head)
	{
		next_node = (*head)->next; /* Store the next node */
		(*head)->next = prev_node; /* Reverse the current node'*/
		prev_node = *head; /* Move prev_node one step forward */
		*head = next_node; /* Move head to the next node */
	}

	*head = prev_node; /* Update head to point to the new */
	return (*head); /* Return the pointer to the first node */
}
