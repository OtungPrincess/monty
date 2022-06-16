#include "monty.h"

/**
 * check_args - check the arguments for monty
 * @argc: argument count
 * @argv: argument vector
 * Return: FILE stream
 */
FILE *check_args(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * init_monty - initialize globla variable
 * @fd: File descriptor
 */
void init_monty(FILE *fd)
{
	data.fd = fd;
	data.mline = 0;
	data.stack = NULL;
	data.arg = NULL;
	data.line = NULL;
	data.operate = "stack";
}

/**
 * free_monty - initialize global variable
 */
void free_monty(void)
{
	while (data.stack && data.stack->next)
	{
		data.stack = data.stack->next;
		if (data.stack)
			free(data.stack->prev);
	}
	if (data.stack)
		free(data.stack);
	if (data.line)
		free(data.line);
	fclose(data.fd);
}

/**
 * main - the main operations take place
 *
 * @argc: number of argument
 * @argv: elements of argument
 * Return: 0 if succesful else another number if not
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	ssize_t flag;
	size_t len = 0;
	char *opcode;
	void (*f)(stack_t **stack, unsigned int mline);
	const char DELIMITER[4] = " \t\n";

	fd = check_args(argc, argv);
	init_monty(fd);
	while ((flag = getline(&data.line, &len, fd) != -1))
	{
		data.mline++;
		opcode = strtok(data.line, DELIMITER);
		if (opcode && opcode[0] != '#')
		{
			data.arg = strtok(NULL, DELIMITER);

			f = get_ops(opcode);
			if (!f)
			{
				dprintf(2, "L%d: unknown instruction %s\n", data.mline, opcode);
				free_monty();
				exit(EXIT_FAILURE);
			}
			f(&data.stack, data.mline);
		}
	}

	free_monty();
	return (EXIT_SUCCESS);
}
