#include "monty.h"

/**
 * op_sub_error - function that returns error when sub fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_sub_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_mul_error - function that returns error when mul fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_mul_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_div_error - function that returns error when div fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_mod_error - function that returns error when mod fails
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_mod_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * op_div_zero_error - returns error for when function divides by 0
 * @line_number: line error occured
 *
 * Return: EXIT_FAILURE always
 */
int op_div_zero_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

