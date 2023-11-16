#include "monty.h"

/**
 * push - function to push an elemnet onto a stack
 * @stack: pointer to an array
 * @num: element to be added
 */
void push(stack_t **stack, int num)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - function that prints all values on the stack
 * @stack: pointer to an array
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
