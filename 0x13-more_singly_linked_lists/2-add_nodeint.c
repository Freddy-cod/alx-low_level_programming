#include "lists.h"

/**
 * add_nodeint - appends a new node at the beginning of a linked list.
 * @head: A pointer to the pointer of the first node in the list.
 * @n: The data to insert in the new node.
 *
 * Return: A pointer to the new node, or NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node; /* Pointer to the new node */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n; /* Set the data of the new node */
	new_node->next = *head; /* Point the new node to the current head */
	*head = new_node; /* Update the head to point to the new node */

	return (new_node); /* Return the new node */
}

