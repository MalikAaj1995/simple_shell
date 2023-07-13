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
	char **list, eof;
	node_t *mynode;
	pid_t pid;

	buffer = malloc(n);
	while (1)
	{
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
		list = nodetolist(&mynode);
		pid = fork(); /* create a child process*/
		if (pid == 0)
			execve(list[0], list, environ);
		wait(NULL);
	}
	return (0);
}
