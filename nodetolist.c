#include "shell.h"

/**
 * nodetolist - convert struct node to a list.
 * @head: pointer to the linked list.
 * 
 * Return: list.
 */
char **nodetolist(node_t **head)
{
	char **list, *ptr;
	int i;

	ptr = *head;
	for (i = 2; ptr->next; i++)
		ptr = ptr->next;
	list = malloc(i * sizeof(head));
	ptr = *head;
	for (i = 0; ptr; i++)
	{
		list[i] = _strdup(ptr);
		ptr = ptr->next;
	}
	list[i] = NULL;
	return (list);
}
