#include "shell.h"

/**
 * main - function that entry point
 *
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t n = 0;
	int buff = 0;

	while (1)
	{
		write(1, "$ ", 2);
		buff = getline(&buffer, &n, stdin);
		if (buff == EOF)
		{
			perror("getline");
		}
		buffer[buff - 1] = '\0';
		printf("%s\n", buffer);
	}
	return (0);
}
