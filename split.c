#include "shell.h"
/**
 * **splitter - function that expected to split the string into
 * multiple substrings
 *
 * @str: pointer to a character
 * @del: delimitters for string
 *
 * Return: array of strings
 */
char **splitter(char *str, char *del)
{
	char *token, **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, del);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	for (i = 0; tokens[i]; i++)
		printf("%s\n", tokens[i]);
	return (tokens);
}
