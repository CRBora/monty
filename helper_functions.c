#include "monty.h"
#include <stdio.h>

/**
 * is_digit - function that checks for a digit
 * @str: pointer to string being checked
 *
 * Return: ) if digit otherwise returns 1
 */
int is_digit(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

/**
 * * clean_resources - function to clean up resources
 * @file: monty file
 * @line: pointer to character array
 */
void clean_resources(FILE *file, char *line)
{
	free(line);
	fclose(file);
}

/**
 * process_line - function to process each line of the Monty bytecode
 * @line: pointer to character array being processed
 * @line_number: line number in the Monty bytecode file
 * @stack: double pointer to the head of the stack
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode = strtok(line, " \t\n");
	int num;

	if (!opcode)
		return;
	if (strcmp(opcode, "push") == 0)
	{
		char *arg = strtok(NULL, " \t\n");

		if (!arg || !is_digit(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		num = atoi(arg);

		push(stack, num);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
