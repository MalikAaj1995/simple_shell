#include "shell.h"

/**
 * execute - execute commands with it's argument
 * @mynode: linked list of commands with arguments.
 *
 * Return: 0 if true, otherwise -1.
 */
int execute(node_t *mynode)
{
	char **list, *cmd;
	pid_t pid;

	cmd = findpath(mynode->str);
	if (cmd == NULL)
	{
		perror(mynode->str);
		freenode(mynode);
		return (-1);
	}
	list = nodetolist(&mynode);
	pid = fork();
	if (pid == 0)
	{
		execve(cmd, list, environ);
		free(cmd);
		freenode(mynode);
		freelist(list);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	free(cmd);
	freenode(mynode);
	freelist(list);
	return (0);
}
