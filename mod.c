#include "monty.h"
/**
 * mod_f - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @cntr: line number
 * Return: no return
*/
void mod_f(stack_t **head, unsigned int cntr)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
