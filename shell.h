#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
extern int errno;

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
char *findpath(char *cmd);
int _which(char *path);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
<<<<<<< HEAD
char *custom_getline();
void processTokens(char *str, const char *delimiters);
=======
int _strcmp(char *s1, char *s2);
void freelist(char **list);
int execute(node_t *mynode);
>>>>>>> 27d5a5d729e9e5b979f72da1c53bc6fa34463e3a

#endif
