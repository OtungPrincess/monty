#include "monty.h"

/**
 * set_stack - sets the format of the data to a stack (LIFO)
 *
 * @stack: first node in the list
 * @mline: current line
 */
void set_stack(stack_t **stack, unsigned int mline)
{
	(void)stack;
	(void)mline;

	data.operate = "stack";
}

/**
 * set_queue - sets the format of the data to a queque (FIFO)
 *
 * @stack: first node in the list
 * @mline: current line
 */
void set_queue(stack_t **stack, unsigned int mline)
{
	(void)stack;
	(void)mline;

	data.operate = "queue";
}
