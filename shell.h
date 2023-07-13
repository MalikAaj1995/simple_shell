#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

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

node_t *addnode(node_t **head, const char *str);
char *_strdup(const char *str);
char **nodetolist(node_t **head);
void freenode(node_t *head);
void findpath(char *cmd);
int _which(char *path);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

#endif
