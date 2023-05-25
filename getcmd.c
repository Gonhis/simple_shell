#include "shell.h"
/**
 * *get_cmd - function that allowd to find cmd
 *
 * @cmd: command to find
 *
 * Return: NULL
 */
char *get_cmd(char *cmd)
{
	char *path = _getenv("PATH");
	char *token, *fcmd;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		fcmd = malloc(strlen(token) + strlen(cmd) + 2);
		strcpy(fcmd, token);
		strcat(fcmd, "/");
		strcat(fcmd, cmd);
		if (stat(fcmd, &st) == 0)
			return (fcmd);
		free(fcmd);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
