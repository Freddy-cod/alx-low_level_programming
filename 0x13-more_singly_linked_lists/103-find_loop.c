#include "lists.h"

/**
 * find_listint_loop - returns the loop in a linked list.
 * @head: Pointer to the head of the linked list to search for a loop.
 *
 * Return: NULL if there's no loop or address.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr = head; /* Slow pointer */
	listint_t *fast_ptr = head; /* Fast pointer */

	if (!head)
		return (NULL);

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;

		if (fast_ptr == slow_ptr) /* Loop detected */
		{
			slow_ptr = head; /* Move slow pointer to the head */

			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			return (fast_ptr); /* Return the address */
		}
	}

	return (NULL); /* No loop found, return NULL */
}
