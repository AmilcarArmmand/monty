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
