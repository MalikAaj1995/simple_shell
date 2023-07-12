#include "shell.h"

/**
 *  * _strdup - copy a string to allocated memory.
 *   * @str: pointer to string.
 *    *
 *     * Return: the pointer to allocated memory, otherwise NULL.
 *      */
char *_strdup(const char *str)
{
	char *p;
	int size = 0;

	if (str == 0)
		return (0);
	while (str[size] != '\0')
		size++;
	size++;
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
	{
		p[size] = str[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}
