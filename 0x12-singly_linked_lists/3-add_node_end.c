#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a linked list.
 *
 * @list_head: Pointer to the list_t list.
 * @new_string: String to store in the node.
 *
 * Returns: Pointer to the newly added node, or NULL if it failed.
 */
list_t *add_node_end(list_t **list_head, const char *new_string)
{
	size_t string_length;
	list_t *new_node;
	list_t *temp;

	/* Calculate the length of the string. */
	string_length = strlen(new_string);

	/* Allocate memory for the new node. */
	new_node = malloc(sizeof(list_t) + string_length + 1);

	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node. */
	new_node->str = (char *)new_node + sizeof(list_t);
	memcpy(new_node->str, new_string, string_length + 1);
	new_node->len = string_length;
	new_node->next = NULL;

	/* If the list is empty, the new node is the head. */
	if (*list_head == NULL)
	{
		*list_head = new_node;
		return (new_node);
	}

	/* Otherwise, iterate through the list to find the end. */
	temp = *list_head;

	while (temp->next != NULL)
		temp = temp->next;

	/* The new node is now the last node in the list. */
	temp->next = new_node;

	return (new_node);
}

