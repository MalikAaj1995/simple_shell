#include <unistd.h>
#include <string.h>
/**
 * processTokens - tokenize a string using the strtok function
 * @str : string
 * @delimiters :  referred to a string containing the delimiter characters
 * Return : None
 */

void processTokens(char *str, const char *delimiters)
{	
	char *token = strtok(str, delimiters);

	while (token != NULL)
	{
	size_t tokenLength = strlen(token);

	write(STDOUT_FILENO, token, tokenLength);
	write(STDOUT_FILENO, "\n", 1);

	token = strtok(NULL, delimiters);
	}
}
/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
        char str[] = "Simple shell project.";
        char delimiters[] = " ,!";

        processTokens(str, delimiters);
        return (0);
}
