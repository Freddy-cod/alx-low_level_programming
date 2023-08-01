include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list.
 * @head: Pointer to the first element in the linked list.
 *
 * Return: The data inside the element that was deleted,
 *         or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *next_node;
	int deleted_data;

	/* Check if the list is empty or the head pointer is NULL. */
	if (!head || !*head)
		return (0);

	deleted_data = (*head)->n; /* Store the data of the head node */
	next_node = (*head)->next; /* Store the next node */
	free(*head); /* Free the head node */
	*head = next_node; /* Update the head */

	return (deleted_data); /* Return the data of the deleted node */
}
