#include "shell.h"

/**
 * findpath - find the path of a command
 * @cmd: command.
 */
void findpath(char *cmd)
{
	char *path, *dir, *new;
	int pass = 0;

	if (_which(cmd))
	{
		path = _strdup(getenv("PATH"));
		dir = strtok(path, ":");
		while (dir)
		{
			new = malloc(_strlen(dir) + _strlen(cmd) + 2);
			_strcat(new, dir);
			_strcat(_strcat(new, "/"), cmd);
			if (!_which(cmd))
			{
				free(path);
				free(cmd);
				cmd = new;
				pass = 1;
				break;
			}
			dir = strtok(NULL, ":");
			free(new);
		}
		if (!pass)
		{
			free(path);
			free(cmd);
			cmd = NULL;
		}
	}
}

/**
 * _which - chec if a command exists
 * @path: command path.
 *
 * Return: 0 if true, otherwise -1.
 */
int _which(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode) || access(path, F_OK | X_OK))
		{
			return (-1);
		}
		return (0);
	}
	return (-1);
}
