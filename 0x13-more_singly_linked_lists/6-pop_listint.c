#include "lists.h"

/**
 * pop_listint - Removes the first element of a linked list.
 * @head: Pointer to the first element in the linked list.
 *
 * Return: The data inside the element that was removed,
 *         or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp; /* Temporary pointer  */
	int data; /* store the data of the removed node */

	/* Check if list is empty or  NULL. */
	if (!head || !*head)
		return (0);

	data = (*head)->n; /* Store the data of the head node */
	temp = (*head)->next; /* Store the next node */

	free(*head); /* Free the head node */
	*head = temp; /* Update the head to point */

	return (data); /* Return the data of the removed node */
}
