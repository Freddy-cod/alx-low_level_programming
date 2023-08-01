#include "lists.h"

/**
 * add_nodeint_end - Appends new node at the end of a linked list.
 * @head: Pointer to the pointer of the first element in the list.
 * @n: Data to insert in the new element.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node; /* Pointer to the new node */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n; /* Set the data of the new node */
	new_node->next = NULL; /* new node - last,next is NULL */

	if (*head == NULL)
	{
		/* If empty-new node the head and return */
		*head = new_node;
		return (new_node);
	}
	else
	{
		/* If empty, find last node & append the new node */
		listint_t *last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
		return (new_node);
	}
}
