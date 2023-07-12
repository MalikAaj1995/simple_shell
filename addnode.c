#include "shell.h"

/**
 * addnode - adds a new node at the end of a argv_t list.
 * @head: pointer to pointer to the start of node.
 * @str: string to add.
 *
 * Return: the address of the new element, or NULL.
 */
argv_t *addnode(argv_t **head, const char *str)
{
	argv_t *new, *ptr;
	int i;

	new = malloc(sizeof(argv_t));
	if (new == NULL)
		return (NULL);

	new->str = _strdup((char *)str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	ptr = *head;
	for (i = 0; ptr->next; i++)
		ptr = ptr->next;
	ptr->next = new;
	return (new);
}
