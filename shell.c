#include "shell.h"

/**
 * main - mini shell
 *
 * Return: 0 .
 */
int main(void)
{
	size_t n = 1024;
	char *buffer, *ptr;
	char **list, eof, *exit_n = "exit";
	node_t *mynode;
	pid_t pid;

	buffer = malloc(n);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		eof = getline(&buffer, &n, stdin); /* read the line from stdin*/
		if (eof == EOF)  /*check the end of a file*/
			exit(EXIT_SUCCESS);
		mynode = NULL;
		ptr = strtok(buffer, " \n"); /*tokenize when there is a space or new line */
		while (ptr) /*enter until the line finish*/
		{
			addnode(&mynode, ptr);
			ptr = strtok(NULL, " \n");
		}
		if (!mynode) /*if mynode is empty (only space or \n) got to the begining */
			continue;
		if (_strcmp(mynode->str, exit_n) == 0)
		{
			free(buffer);
			freenode(mynode);
			exit(EXIT_SUCCESS);
		}
		execute(mynode);
	}
	return (0);
}
