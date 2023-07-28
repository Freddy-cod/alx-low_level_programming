#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: Defines a node for a singly linked list.
 * Each node stores a string and its length, and a pointer
 * to the next node in the list.
 */
typedef struct list_s
{
    char *str;              /* String data - dynamically allocated */
    unsigned int len;       /* Length of the string */
    struct list_s *next;    /* Pointer to the next node in the list */
} list_t;

/**
 * print_list - Print all elements of a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h);

/**
 * list_len - Count the number of nodes in a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h);

/**
 * add_node - Add a new node at the beginning of the linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @str: String to be stored in the new node.
 *
 * Return: Pointer to the newly created node.
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - Add a new node at the end of the linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @str: String to be stored in the new node.
 *
 * Return: Pointer to the newly created node.
 */
list_t *add_node_end(list_t **head, const char *str);

/**
 * free_list - Free the memory allocated for a linked list.
 * @head: Pointer to the head of the list to be freed.
 *
 * Description: This function frees all the nodes in the linked list,
 * including the strings stored in each node.
 */
void free_list(list_t *head);

#endif

