#include "monty.h"

/**
 * file_open_error - function that returns error when file open fails
 * @filename: the name of the file to open
 *
 * Return: EXIT_FAILURE always
 */
int file_open_error(char *filename)
{
	printf("hello world");
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * op_push_error - function that returns error when push fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_push_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_pop_error - function that returns error when pop fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_add_error - function that returns error when add fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_add_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_swap_error - function that returns error when swap fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	return (EXIT_FAILURE);
}