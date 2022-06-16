#include "monty.h"

/**
 * get_ops - pointer that executes called stack instructions
 * @opcode: string copy of stack instruction
 * Return: function for the opcode
 */
void (*get_ops(char *opcode))(stack_t **stack, unsigned int mline)
{
	unsigned int c;
	instruction_t all_ops[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "add", add },
		{ "nop", nop },
		{ "pop", pop },
		{ "sub", sub },
		{ "div", set_div },
		{ "mul", mul },
		{ "mod", mod },
		{ "pchar", pchar },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "stack", set_stack },
		{ "queue", set_queue },
		{ NULL, NULL }
	};

	for (c = 0; all_ops[c].opcode; c++)
	{
		if (strcmp(opcode, all_ops[c].opcode) == 0)
			return (all_ops[c].f);
	}
	return (NULL);
}
