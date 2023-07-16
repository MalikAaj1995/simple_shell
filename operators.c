#include "shell.h"

/**
 * operators - handle command aand logical operators
 * @line: command line.
 *
 * Return: 1 if there is no operators, otherwise 0..
 */
int operators(char *line)
{
	char *start;
	node_t *commands;

	addnode(&commands, NULL);
	addnode(&commands, NULL);
	commands->str = line;
	commands->next->str = start = line;
	while (*start != '\n')
	{
		if (_strncmp(start, " #", 2))
		{
			start[0] = '\0';
			execute(commands);
			return (0);
		}
		else if (_strncmp(start, " ; ", 3))
		{
			start[0] = '\0';
			execute(commands);
			commands->next->str = start + 3;
		}
		else if (_strncmp(start, " && ", 4))
		{
			start[0] = '\0';
			if (!execute(commands))
				return (0);
			commands->next->str = start + 4;
		}
		else if (_strncmp(start, " || ", 4))
		{
			start[0] = '\0';
			if (execute(commands))
				return (0);
			commands->next->str = start + 4;
		}
		start++;
	}
	execute(commands);
	return (1);
}
