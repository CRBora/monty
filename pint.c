#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number in the Monty bytecode file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
