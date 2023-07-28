#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Appends a new node at the end of a linked list.
 *
 * @head: Pointer to the list_t list.
 * @str: String to store in the node.
 *
 * Return: Pointer to the newly added node, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;           /* Pointer to the new node */
	list_t *temp = *head;  /* Temporary pointer to traverse the list */
	unsigned int len = 0; /* Length of the input string */

	/* Calculate the length of the input string */
	while (str[len])
		len++;

	/* Allocate memory for the new node */
	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	/* Duplicate the input string using strdup */
	new->str = strdup(str);

	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	/* Initialize the new node */
	new->len = len;
	new->next = NULL;

	/* If the list is empty, the new node is the head */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* Otherwise, traverse the list to find the end */
	while (temp->next)
		temp = temp->next;

	/* The new node becomes the last node in the list */
	temp->next = new;

	return (new);
}
