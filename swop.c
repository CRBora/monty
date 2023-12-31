#include "monty.h"

/**
 * swap - function to swap the top two elements of the stack.
 * @stack: double pointer to the head of the stack.
 * @line_number: line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
