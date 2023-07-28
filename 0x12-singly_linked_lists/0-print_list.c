#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all the elements of a linked list.
 * @h: Pointer to the list_t list to print.
 *
 * Return: The number of nodes printed.
 */
size_t print_list(const list_t *h)
{
    /* Base case: If the current node is NULL, the list is empty, return 0. */
    if (h == NULL)
    {
        return 0;
    }

    /* Print the current node's data */
    if (h->str == NULL)
    {
        printf("[0] (nil)\n"); /* If the string is NULL, print [0] (nil) */
    }
    else
    {
        printf("[%u] %s\n", h->len, h->str); /* Print the length and the string */
    }

    /* Make a recursive call to print_list with the next node (h->next). */
    /* The recursive call will handle the rest of the list. */
    /* The return value of the recursive call will be the number of nodes */
    /* printed in the remaining part of the list. */
    return 1 + print_list(h->next);
}

