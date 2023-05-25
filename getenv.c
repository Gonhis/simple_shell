#include "shell.h"
/**
 * *_getenv - function is used to retrieve the value of an
 * environment variable
 *
 * @name: name of the environment variable
 *
 * Return: NULL
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *vr;

	while (environ[i])
	{
		vr = strtok(environ[i], "=");
		if (strcmp(vr, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
