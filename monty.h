#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>


typedef struct glob_vars
{
	int glob_int;
} glob_t;

extern glob_t glob_vars;
glob_t glob_vars;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _sfree(stack_t *args);
void _free(stack_t **head, unsigned int n);
char *get_line(char *file);
char **split_line(char *line);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int is_number(char *commands);

int checker(unsigned int line_number, char **commands, stack_t **head, FILE *fptr);
void (*_commands(char *opcode, unsigned int ln))(stack_t **stack, unsigned int);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
#endif
