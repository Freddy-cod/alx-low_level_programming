#include "lists.h"

/**
 * insert_nodeint_at_index - Includes new node in a linked list at an index.
 * @head: Its a Pointer to the pointer of the first node list.
 * @idx: index position where the new node is added.
 * @n: the data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node; /* Pointer to the new node */
	listint_t *temporary = *head; /* Pointer to traverse the list */

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head) /* Check for malloc failure,head being NULL */
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0) /* Insert at the beginning of the list */
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; temporary && i < idx; i++) /* Traverse the list to index */
	{
		if (i == idx - 1) /* Insert the new node at the given position */
		{
			new_node->next = temporary->next;
			temporary->next = new_node;
			return (new_node);
		}
		else
			temporary = temporary->next; /* Move to the next node */
	}

	free(new_node); /* If index is out of bounds, free the new node */
	return (NULL);
}
