#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * getline - function is to read a line of input from the user
 *
 * Return : line
 */

#define MAX_LINE_LENGTH 1024

char *custom_getline()
{
	char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
	size_t len = strlen(line);

	if (line == NULL)
	{
		perror("Error: Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	fgets(line, MAX_LINE_LENGTH, stdin);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}

	return (line);
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = custom_getline();

	free(line);
	return (0);
}
