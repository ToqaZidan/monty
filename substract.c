#include "monty.h"
/**
  *sub_f - sustration
  *@head: stack head
  *@cntr: line_number
  *Return: no return
 */
void sub_f(stack_t **head, unsigned int cntr)
{
	stack_t *aux;
	int sub, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*head = aux->next;
	free(aux);
}
