#ifndef MONTY_H
#define MONTY_H

/* dprintf and getline support */
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - global variable for monty interpreter
 * @stack: stack
 * @mline: line number
 * @arg: argument for the instruction
 * @operate: operation to perform (Stack/Queue)
 * @fd: file descriptor
 * @line: line of
 */
typedef struct data_s
{
	stack_t *stack;
	unsigned int mline;
	char *arg;
	char *operate;
	FILE *fd;
	char *line;
} data_t;

extern data_t data;
data_t data;

void free_monty(void);


/* Operations */
void push(stack_t **stack, unsigned int mline);
void pall(stack_t **stack, unsigned int mline);
void pint(stack_t **stack, unsigned int mline);
void pop(stack_t **stack, unsigned int mline);
void swap(stack_t **stack, unsigned int mline);
void add(stack_t **stack, unsigned int mline);
void nop(stack_t **stack, unsigned int mline);
void sub(stack_t **stack, unsigned int mline);
void set_div(stack_t **stack, unsigned int mline);
void mul(stack_t **stack, unsigned int mline);
void mod(stack_t **stack, unsigned int mline);
void pchar(stack_t **stack, unsigned int mline);
void pstr(stack_t **stack, unsigned int mline);
void rotl(stack_t **stack, unsigned int mline);
void rotr(stack_t **stack, unsigned int mline);
void set_stack(stack_t **stack, unsigned int mline);
void set_queue(stack_t **stack, unsigned int mline);

void (*get_ops(char *opcode))(stack_t **stack, unsigned int mline);

/* string functions */
int check_isdigit(char *str);

#endif /* _MONTY_H_ */
