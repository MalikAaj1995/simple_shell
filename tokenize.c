#include "shell.h"

/**
 * tokenize - tokenize a line using strtok
 * @line: command line.
 *
 * Return: tokenized linked list.*
 */
node_t *tokenize(char *line)
{
	node_t *mynode;
	char *ptr;

	mynode = NULL;
	ptr = strtok(line, " \n");
	while (ptr)
	{
		addnode(&mynode, ptr);
		ptr = strtok(NULL, " \n");
	}
	return (mynode);
}
