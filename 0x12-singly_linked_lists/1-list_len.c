#include <stdlib.h>
#include "lists.h"

/**
 * list_len_recursive - Recursively counts elements in the list.
 * @h: Pointer to the list_t list.
 *
 * Return: The number of elements in h.
 */
size_t list_len_recursive(const list_t *h)
{
	if (h == NULL)
		return (0);

	return (1 + list_len_recursive(h->next));
}

/**
 * list_len - Returns the number of elements in a linked list.
 * @h: Pointer to the list_t list.
 *
 * Return: The number of elements in h.
 */
size_t list_len(const list_t *h)
{
	return (list_len_recursive(h));
}

