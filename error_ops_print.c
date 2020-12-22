#include "monty.h"

/**
 * op_pint_error - function that returns error when pint fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_pchar_error - function that returns error when pchar fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_pchar_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_pchar_value_error - throws error if int isn't ascii
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_pchar_value_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	return (EXIT_FAILURE);
}