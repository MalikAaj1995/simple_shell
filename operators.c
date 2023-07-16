#include "shell.h"

/**
 * operators - handle command aand logical operators
 * @line: command line.
 *
 * Return: 1 if there is no operators, otherwise 0..
 */
int operators(char *line)
{
	char *start, *c;
	node_t *tokens;

	start = c = line;
	while (c != '\n')
	{
		if (_strncmp(c, " #", 2))
		{
			c[0] = '\0';
			tokens = tokenize(start);
			execute(tokens);
			return (0);
		}
		else if (_strncmp(c, " ; ", 3))
		{
			c[0] = '\0';
			tokens = tokenize(start);
			execute(tokens);
			start = c + 3;
		}
		else if (_strncmp(c, " && ", 4))
		{
			c[0] = '\0';
			tokens = tokenize(start);
			if (!execute(tokens))
				return (0);
			start = c + 4;
		}
		else if (_strncmp(c, " || ", 4))
		{
			c[0] = '\0';
			tokens = tokenize(start);
			if (execute(tokens))
				return (0);
			start = c + 4;
		}
		c++;
	}
	tokens = tokenize(start);
	execute(tokens);
	return (1);
}
