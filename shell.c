#include "sheel.h"

/**
 * main - mini shell
 *
 * Return: 0 .
 */
int main(void)
{
	int eof, i;
	size_t n = 1024;;
	char *buffer, *ptr;

	buffer = malloc(n);
	while (1)
	{
		eof = getline(&buffer, &n, stdin);
		if (eof == EOF)
			exit(EXIT_SUCCESS);
		ptr = strtok(buffer, " \n");
		while (ptr)
		{
			ptr = strtok(NULL, " \n");
		}
	}
	return (0);
}
