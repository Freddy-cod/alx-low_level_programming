#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Inserts a new node at the beginning of a linked list.
 * @head: Double pointer to the list_t list.
 * @str: New string to store in the node.
 *
 * Return: Pointer to the newly added node, or NULL if it fails.
 */
list_t *add_node(list_t **head, const char *str)
{
	/* Declare a new node pointer and a variable to store the length of str */
	list_t *new_node;
	unsigned int str_len = 0;

	/* Calculate the length of the input string */
	while (str[str_len])
		str_len++;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	/* Duplicate the input string using strdup */
	new_node->str = strdup(str);

	if (!new_node->str) /* Check if strdup failed */
	{
		free(new_node); /* Free the newly created node if strdup fails */
		return (NULL);
	}

	/* Initialize the new node with the given values */
	new_node->len = str_len;
	new_node->next = (*head);

	/* Update the head to point to the new node, making it the new head */
	(*head) = new_node;

	return (*head);
}

