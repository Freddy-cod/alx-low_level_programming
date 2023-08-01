#include "lists.h"

/**
 * get_nodeint_at_index - Finds the node at a specified index
 * @head: Pointer to the first node in the linked list.
 * @index: Index of the node to return.
 *
 * Return: Pointer to the node at the specified index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int current_index = 0; /* Variable to track index */
	listint_t *current_node = head; /* Pointer to traverse list */

	/* Traverse the linked list to find the node at the specified index */
	while (current_node && current_index < index)
	{
		current_node = current_node->next; /* Move to the next node */
		current_index++; /* Increment the current index */
	}

	return (current_node ? current_node : NULL); /* Return the node or NULL */
}
