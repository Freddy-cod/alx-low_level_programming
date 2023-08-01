#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to the pointer of the first node in the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next_node;

	while (current != NULL)
	{
		next_node = current->next; /* Store the next node */
		current->next = prev; /* Reverse the current node's next pointer */
		prev = current; /* Move prev and current one step forward */
		current = next_node;
	}

	*head = prev; /* Update head to point to the new first node */
	return (*head);
}
