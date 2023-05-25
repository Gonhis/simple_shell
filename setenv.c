#include "shell.h"
/**
 * _setenv - function that indicates the success or failure of
 * setting the environment variable
 *
 * @name: represent the name of the environment variable to set
 * @value: represent the value to set for the environment variable
 * @overwrite: integer that specifies whether to overwrite an existing
 *
 * Return: 0
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	int i = 0, len = 0;
	char nvr;

	if (!name || !value)
		return (-1);
	while (environ[i])
	{
		len = strlen(name);
		if (strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				nvr = malloc(strlen(name) + strlen(value) + 2);
				strcpy(nvr, name);
				strcat(nvr, "=");
				strcat(nvr, value);
				environ[i] = nvr;
				return (0);
			}
			return (0);
		}
		i++;
	}
	nvr = malloc(strlen(name) + strlen(value) + 2);
	strcpy(nvr, name);
	strcat(nvr, "=");
	strcat(nvr, value);
	environ[i] = nvr;
	environ[i + 1] = NULL;
	return (0);
}
