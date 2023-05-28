#include "monty.h"
/**
 * pall_f - prints the stack
 * @head: stack head
 * @cntr: not used
 * Return: no return
*/
void pall_f(stack_t **head, unsigned int cntr)
{
        stack_t *h;
        (void)cntr;

        h = *head;
        if (h == NULL)
                return;
        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}
