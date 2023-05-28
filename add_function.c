#include "monty.h"
/**
 * add_f - function that adds the top two elements of the stack.
 * @head: stack head
 * @cntr: line_number
 * Return: no return
*/
void add_f(stack_t **head, unsigned int cntr)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
