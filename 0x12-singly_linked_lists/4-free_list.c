#include <stdlib.h>
#include "lists.h"

/**
 * free_list_recursive - Recursively frees a linked list.
 * @head: Pointer to the list_t list to be freed.
 */
void free_list_recursive(list_t *head)
{
	if (head == NULL)
		return;

	free_list_recursive(head->next);
	free(head->str);
	free(head);
}

/**
 * free_list - Frees a linked list using recursion.
 * @head: Pointer to the list_t list to be freed.
 */
void free_list(list_t *head)
{
	free_list_recursive(head);
}

