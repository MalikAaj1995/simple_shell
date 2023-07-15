#include "shell.h"

/**
 * execute - execute commands with it's argument
 * @mynode: linked list of commands with arguments.
 *
 * Return: 0 if true, otherwise -1.
 */
int execute(node_t *mynode)
{
	char **list, *old;
	pid_t pid;

	old = mynnode->str;
	mynode->str = findpath(mynode->str);
	if (mynode->str == NULL)
	{
		perror(old);
		return (-1);
	}
	list = nodetolist(&mynode);
	pid = fork();
	if (pid == 0)
	{
		execve(list[0], list, environ);
		freenode(mynode);
		freelist(list);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	freenode(mynode);
	freelist(list);
	return (0);
}
