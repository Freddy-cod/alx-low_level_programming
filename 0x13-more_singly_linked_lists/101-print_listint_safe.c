#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts unique nodes in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If not looped return 0 else num of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t unique_nodes = 1; /* Counter for the number of unique nodes */

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				unique_nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				unique_nodes++;
				tortoise = tortoise->next;
			}

			return (unique_nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - returns a listint_t list safely.
 * @head: Pinter to the head of the list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes, index = 0;

	num_nodes = looped_listint_len(head);

	if (num_nodes == 0) /* If the list is not looped */
	{
		for (; head != NULL; num_nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else /* If the list is looped */
	{
		for (index = 0; index < num_nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (num_nodes);
}

