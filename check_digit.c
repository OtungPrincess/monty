#include "monty.h"
/**
 * check_isdigit - prints the return value is digit or not
 * @str: string to check
 * Return: 1 if it's digit and 0 if not
 */
int check_isdigit(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
	{
		if ((str[c] < '0' || str[c] > '9'))
			return (0);
	}
	return (1);
}
