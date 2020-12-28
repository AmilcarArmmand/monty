#include "monty.h"

/**
 * file_open_error - function that returns error when file open fails
 * @filename: the name of the file to open
 *
 * Return: EXIT_FAILURE always
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * stack_malloc_error - error function in case malloc fails for stack
 *
 * Return: EXIT_FAILURE always
 */
int stack_malloc_error(void)
{
	fprintf(stderr, "Error: failed to malloc stack\n");
	return (EXIT_FAILURE);
}

/**
 * usage_error - function that checks that the number of arguments given is 2
 *
 * Return: EXIT_FAILURE always
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * unknown_instruct - checks that the number of arguments given is 2
 * @line_number: the line number where the command usage error occurred
 * @token: the command token for the given line
 *
 * Return: EXIT_FAILURE always
 */
int unknown_instruct(unsigned int line_number, char *token)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc failed error message to stderr
 *
 * Return: EXIT_FAILURE always
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
