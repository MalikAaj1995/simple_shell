#include "shell.h"

/**
 * execute - execute commands with it's argument
 * @line: linked list of commands.
 *
 * Return: 0 if true, otherwise -1.
 */
int execute(node_t *line)
{
	char **list, *cmd;
	pid_t pid;
	int status;
	node_t *mynode;

	mynode = tokenize(line->next->str);
	cmd = findpath(mynode->str);
	if (cmd == NULL)
	{ 
		write(1, ": ", 2);
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
		freenode(line);
		freenode(mynode);
		freelist(list);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(cmd);
	freenode(mynode);
	freelist(list);
	if (!WIFEXITED(status))
		return (-1);
	return (0);
}
