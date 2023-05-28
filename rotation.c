#include "monty.h"
/**
  *rotate - rotates the stack to the top
  *@head: stack head
  *@cntr: line number
  *Return: no return
 */
void rotate(stack_t **head,  __attribute__((unused)) unsigned int cntr)
{
	stack_t *temp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = aux;
}


/**
  *rev_rotate- rotates the stack to the bottom
  *@head: stack head
  *@cntr: line_number
  *Return: no return
 */
void rev_rotate(stack_t **head, __attribute__((unused)) unsigned int cntr)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
