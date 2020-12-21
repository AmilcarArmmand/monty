#include "monty.h"

/**
 * file_open_error - function that returns error when file open fails
 * @filename: the name of the file to open
 *
 * Return: EXIT_FAILURE always
 */
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * strack_malloc_error - error function in case malloc fails for stack
 *
 * Return: EXIT_FAILURE always
 */
int stack_malloc_error(void)
{
	fprintf(stderr, "Error: failed to malloc stack\n");
	return (EXIT_FAILURE);
}

