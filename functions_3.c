#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: first node in the list
 * @mline: line  currently on
 */
void mod(stack_t **stack, unsigned int mline)
{
	stack_t *later;

	later = *stack;
	if (!later || !later->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", mline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if (later->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", mline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	later->next->n %= later->n;	/* next value updated */
	later = later->next;
	later->prev = NULL;
	free(*stack);
	*stack = later;
}

/**
 * pchar - returns the char at the top of stack
 *
 * @stack: first node in list
 * @mline: line  currently on
 */
void pchar(stack_t **stack, unsigned int mline)
{
	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", mline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", mline);
		free_monty();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints string starting at the top of stack
 *
 * @stack: first node in the list
 * @mline: current line
 */
void pstr(stack_t **stack, unsigned int mline)
{
	stack_t *tmp;
	(void) mline;

	tmp = *stack;
	while (tmp && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: first node in the list
 * @mline: current line
 */
void rotl(stack_t **stack, unsigned int mline)
{
	stack_t *current, *head;

	(void) mline;

	if (!*stack)
		return;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	current->next = head; /* convert linked list a cycle */
	*stack = head->next; /* convert stack top to be second node */
	head->next = NULL;
	head->prev = current;
}

/**
 * rotr - rotates the stack to the top
 *
 * @stack: first node in the list
 * @mline: current line
 */
void rotr(stack_t **stack, unsigned int mline)
{
	stack_t *current, *head;

	(void) mline;

	if (!*stack)
		return;

	current = head = *stack;
	while (current && current->next)
		current = current->next;

	current->next = head; /* linked list bcoms a cycle */
	head->prev = current;
	current->prev->next = NULL;
	current->prev = NULL;
	*stack = current;
}
