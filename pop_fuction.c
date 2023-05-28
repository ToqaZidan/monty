#include "monty.h"
/**
 * pop_f - function that prints the top of the stack
 * @head: head of the stack
 * @cntr: line_number
 * Return: no return
*/
void pop_f(stack_t **head, unsigned int cntr)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
