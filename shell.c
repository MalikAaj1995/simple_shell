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
	char eof, *exit_n = "exit";
	/*node_t *mynode;*/

	buffer = malloc(n);
	while (1)
	{
		errno = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		eof = getline(&buffer, &n, stdin); /* read the line from stdin*/
		if (eof == EOF)  /*check the end of a file*/
			exit(EXIT_SUCCESS);
		/*mynode = NULL;
		ptr = strtok(buffer, " \n");
		while (ptr)
		{
			addnode(&mynode, ptr);
			ptr = strtok(NULL, " \n");
		}
		if (!mynode)
			continue;*/
		/*if (_strcmp(mynode->str, exit_n) == 0)
		{
			free(buffer);
			freenode(mynode);
			exit(errno);
		}
		execute(mynode);*/
		operators(buffer);
	}
	return (0);
}
