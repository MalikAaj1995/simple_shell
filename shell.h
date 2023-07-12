#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>

/**
 * * struct node - singly linked list
 * @str: string.
 * @next pointer to next node.
 */
typedef struct node
{
	char *str;
	struct node *next;
} node_t;
