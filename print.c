#include "monty.h"
/**
 * print_char - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @cntr: line_number
 * Return: no return
*/
void print_char(stack_t **head, unsigned int cntr)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

#include "monty.h"
/**
 * print_str - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @cntr: line number
 * Return: no return
*/
void print_str(stack_t **head, unsigned int cntr)
{
	stack_t *h;
	(void)cntr;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
