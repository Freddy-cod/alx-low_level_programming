#include "lists.h"

/**
 * free_listint2 - This Frees a linked list.
 * @head: Double pointer to the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	listint_t *current_node;
	listint_t *next_node;

	current_node = *head;

	while (current_node)
	{
		next_node = current_node->next; /* Store the next node */
		free(current_node); /* Free the current node */
		current_node = next_node; /* Move to the next node */
	}

	*head = NULL; /* Reset the head pointer to NULL */
}
