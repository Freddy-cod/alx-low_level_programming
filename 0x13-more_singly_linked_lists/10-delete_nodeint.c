#include "lists.h"

/**
 * delete_nodeint_at_index - removes the node at an index in list.
 * @head: Pointer to the pointer of the first node in the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if deletion is successful, -1 if fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev_node;
	unsigned int i;

	if (!head || !*head) /* Check if the list is empty or NULL */
		return (-1);

	if (index == 0) /* If index is 0, delete the first node */
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}

	prev_node = *head;
	temp = (*head)->next;

	for (i = 1; temp; i++) /* Traverse the list to the desired index */
	{
		if (i == index) /* Delete the node at the given index */
		{
			prev_node->next = temp->next;

			free(temp);
			return (1);
		}

		prev_node = temp;
		temp = temp->next;
	}

	return (-1); /* If index is out of bounds, return -1 */
}
