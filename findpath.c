#include "shell.h"

/**
 * findpath - find the path of a command
 * @cmd: command.
 */
void findpath(char *cmd)
{
	char *path, *dir, *new;

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
				break;
			}
			dir = strtok(NULL, ":");
			free(new);
		}
		free(path);
		free(cmd);
		cmd = NULL;
	}
}

