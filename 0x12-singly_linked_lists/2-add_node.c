#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: Double pointer to the list_t list.
 * @str: New string to add in the node.
 *
 * Return: The address of the new element, or NULL if it fails.
 */
list_t *add_node(list_t **head, const char *str)
{
	if (str == NULL)
		return (NULL);

	list_t *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	/* Duplicate the input string using strdup */
	new->str = strdup(str);

	if (new->str == NULL)
	{
		free(new); /* Free the newly created node if strdup fails */
		return (NULL);
	}

	/* Calculate the length of the input string */
	new->len = strlen(str);

	new->next = *head;

	*head = new;

	return (*head);
}

