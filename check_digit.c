#include "monty.h"
/**
 * check_isdigit - checks string is only digit
 * @str: string to check
 * Return: 1 if it's digit and 0 if not
 */
int check_isdigit(char *str)
{
	int c;

	for (c = 0; str[c]; c++)
	{
	if (str[c] == '-' && c == 0)
	continue;
	if (isdigit(str[c]) == 0)
	return (1);
	}
	return (0);
}
