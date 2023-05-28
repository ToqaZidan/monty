#include "monty.h"
/**
 * push_f - function that pushs node to the stack
 * @head: stack head
 * @cntr: line_number
 * Return: no return
*/
void push_f(stack_t **head, unsigned int cntr)
{
	int n, j = 0, flag = 0;

	if (omnibus.arg)
	{
		if (omnibus.arg[0] == '-')
			j++;
		for (; omnibus.arg[j] != '\0'; j++)
		{
			if (omnibus.arg[j] > 57 || omnibus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", cntr);
			fclose(omnibus.file);
			free(omnibus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", cntr);
		fclose(omnibus.file);
		free(omnibus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(omnibus.arg);
	if (omnibus.stqu == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
