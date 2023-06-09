#include "shell.h"

/**
 * main - function that entry point
 *
 * @ac: number of command-line arguments
 * @av:  array of command-line arguments
 * @env: environment
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t n = 0;
	int buff;
	int status;
	char *ncmd, **args;
	pid_t pid;
	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);
		buff = getline(&buffer, &n, stdin);
		if (buff == EOF)
		{
			perror("getline");
		}
		buffer[buff - 1] = '\0';
		args = splitter(buffer, " \t\n");
		if (strcmp(args[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			ncmd = get_cmd(args[0]);
			if (ncmd)
				execve(ncmd, args, env);
			else
				printf("command not found\n");
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}
