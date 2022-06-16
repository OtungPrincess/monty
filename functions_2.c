#include "monty.h"

/**
 * add - sums the top two elements of the stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void add(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp->next->n += tmp->n;	/* value of next updated */
	tmp = tmp->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}

/**
 * nop - does nothing
 *
 * @stack: first node in the list
 * @mline: current line
 */
void nop(stack_t **stack, unsigned int mline)
{
	(void)stack;
	(void)mline;
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 *
 * @stack: first node in the list
 * @mline: current line
 */
void sub(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp->next->n -= tmp->n;	/* value of next updated */
	tmp = tmp->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}

/**
 * set_div - divides the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: first node in the list
 * @mline: current line
 */
void set_div(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", mline);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp->next->n /= tmp->n;	/* update value of next */
	tmp = tmp->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}

/**
 * mul -  multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: first node in the list
 * @mline: current line
 */
void mul(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp->next->n *= tmp->n;	/* value of next updated */
	tmp = tmp->next;
	tmp->prev = NULL;
	free(*stack);
	*stack = tmp;
}
