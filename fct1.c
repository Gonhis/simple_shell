#include "shell.h"
/**
 * _strcmp - function that compares two strings
 *
 * @s1: string
 * @s2: string
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * strncmp - function that indicate the result of the comparison
 * between the two strings
 *
 * @str1: string
 * @str2: string
 * @n: maximum number of characters to compare
 *
 * Return: str1 - str2 or 0
 */
int strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
