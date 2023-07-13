#include "shell.h"

/**
 * main - mini shell
 *
 * Return: 0 .
 */
int main(void)
{
	int eof;
	size_t n = 1024;;
	char *buffer, *ptr;
	node_t *list;
	pid_t pid;

	buffer = malloc(n);
	while (1)
	{
		eof = getline(&buffer, &n, stdin); /* read the line from stdin*/
		if (eof == EOF)  /*check the end of a file*/
			exit(EXIT_SUCCESS);
		list = NULL;
		ptr = strtok(buffer, " \n"); /*tokenize when there is a space or new line */
		while (ptr) /*enter until the line finish*/
		{
			addnode(list, ptr);
			ptr = strtok(NULL, " \n");
		}
		pid = fork(); /* create a child process*/
		if (pid == 0)
			execve(list->str, list, environ);
		wait(NULL);
	}
	return (0);
}
