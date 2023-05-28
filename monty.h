#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

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
 * struct omnibus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @stqu: flag that change stack <-> queue
 * Description: carries values through the program
 */
typedef struct omnibus_s
{
	char *arg;
	FILE *file;
	char *content;
	int stqu;
}  omnibus_t;
extern omnibus_t omnibus;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_f(stack_t **head, unsigned int number);
void pall_f(stack_t **head, unsigned int number);
void pint_f(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int cntr, FILE *file);
void free_stack(stack_t *head);
void pop_f(stack_t **head, unsigned int cntr);
void swap_f(stack_t **head, unsigned int cntr);
void add_f(stack_t **head, unsigned int cntr);
void nop_f(stack_t **head, unsigned int cntr);
void sub_f(stack_t **head, unsigned int cntr);
void div_f(stack_t **head, unsigned int cntr);
void mul_f(stack_t **head, unsigned int cntr);
void mod_f(stack_t **head, unsigned int cntr);
void print_char(stack_t **head, unsigned int cntr);
void print_str(stack_t **head, unsigned int cntr);
void rotate(stack_t **head, unsigned int cntr);
void rev_rotate(stack_t **head, __attribute__((unused)) unsigned int cntr);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void queue_f(stack_t **head, unsigned int cntr);
void stack_f(stack_t **head, unsigned int cntr);
#endif
