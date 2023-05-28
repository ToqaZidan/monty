#include "monty.h"
/**
 * queue_f - prints the top
 * @head: stack head
 * @cntr: line number
 * Return: no return
*/
void queue_f(stack_t **head, unsigned int cntr)
{
	(void)head;
	(void)cntr;
	omnibus.stqu = 1;
}

/**
 * add_queue - function that adds node to the stack tail
 * @n: new value
 * @head: head of the stack
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *newnode, *aux;

	aux = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
	}
	newnode->n = n;
	newnode->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		aux->next = newnode;
		newnode->prev = aux;
	}
}
