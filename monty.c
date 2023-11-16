#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point to function that processes a monty file
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: processed monty bytecode file
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		process_line(line, line_number, &stack);

		if (strcmp(line, "pint\n") == 0)
			pint(&stack, line_number);
		line_number++;
	}
	clean_resources(file, line);
	return (EXIT_SUCCESS);
}
