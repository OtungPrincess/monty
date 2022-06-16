#include "monty.h"

/**
 * push - adds node to top of stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void push(stack_t **stack, unsigned int mline)
{
	stack_t *new_node, *tmp = *stack;
	int val;

	if (!data.arg || !check_isdigit(data.arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", mline);
		exit(EXIT_FAILURE);
	}
	val = atoi(data.arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val, new_node->next = NULL, new_node->prev = NULL;

	if (!(*stack))
	{
		*stack = new_node;
		return;
	}

	if (strcmp("stack", data.operate) == 0)	/* for (LIFO) */
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
		return;
	}
	if (!(*stack)->next)	/* for queue (FIFO) */
		tmp->next = new_node, new_node->prev = tmp;
	else
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new_node, new_node->prev = tmp;
	}
}

/**
 * pall - print all value of list
 *
 * @stack: first node in the list
 * @mline: current line
 */
void pall(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;
	(void) mline;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	if (tmp == *stack)
		return;
	}
}

/**
 * pint - prints the value at the top of stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void pint(stack_t **stack, unsigned int mline)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", mline);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void pop(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp = tmp->next;
	free(*stack);
	if (tmp)
		tmp->prev = NULL;
	*stack = tmp;
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void swap(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", mline);
		exit(EXIT_FAILURE);
	}

	tmp->prev = tmp->next;
	tmp->next->prev = NULL;
	if (tmp->next->next)
		tmp->next->next->prev = tmp;
	tmp->next = tmp->next->next;
	tmp->prev->next = tmp;
	*stack = tmp->prev;
}
