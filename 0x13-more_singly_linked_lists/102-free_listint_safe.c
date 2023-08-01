#include "lists.h"

/**
 * free_listint_safe - Handling possible loops  & Frees a list, .
 * @h: Pointer to the pointer of the first node.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_elements = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next; /* Calculate the difference */
		if (diff > 0) /* If not looped, free */
		{
			temp = (*h)->next; /* Store the next node */
			free(*h); /* Free the current node */
			*h = temp; /* Move the head pointer */
			num_elements++; /* Increment t */
		}
		else /* If looped or only one element left */
		{
			free(*h); /* Free the current node */
			*h = NULL; /* Set head to NULL  */
			num_elements++; /* Increment */
			break; /* Break the loop */
		}
	}

	*h = NULL; /* Ensure head is set to NULL */

	return (num_elements); /* number of elements freed */
}
