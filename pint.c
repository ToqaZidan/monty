#include "monty.h"
/**
 * pint_f - prints the value at the top of the stack
 * @head: stack head
 * @cntr: line number
 * Return: no return
*/
void pint_f(stack_t **head, unsigned int cntr)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
