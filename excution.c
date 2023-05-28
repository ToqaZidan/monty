#include "monty.h"
/**
* execute - function to executes the opcode
* @stack: head linked list - stack
* @cntr: line numbers
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int cntr, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_f}, {"pall", pall_f}, {"pint", pint_f},
				{"pop", pop_f},
				{"swap", swap_f},
				{"add", add_f},
				{"nop", nop_f},
				{"sub", sub_f},
				{"div", div_f},
				{"mul", mul_f},
				{"mod", mod_f},
				{"pchar", print_char},
				{"pstr", print_str},
				{"rotl", rotate},
				{"rotr", rev_rotate},
				{"queue", queue_f},
				{"stack", stack_f},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, cntr);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", cntr, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
