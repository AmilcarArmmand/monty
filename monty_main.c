#include "monty.h"

/**
 * main - the entry point of the Monty Bytecode Interpreter
 * @argc: the number of arguments passed to main
 * @argv: pointer to an array of pointers to arguments passed to main
 *
 * Return: (EXIT_SUCCESS) for success or (EXIT_FAILURE) for error
 */
int main(int argc, char **argv)
{
	FILE *filestream_fd;
	int exit_code;

	filestream_fd = NULL;
	exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (EXIT_FAILURE); /* call the function that will print to stderror */

	filestream_fd = fopen(argv[1], 'r');
	if (filestream_fd == NULL)
		return (EXIT_FAILURE); /* call function that displays error code */

	exit_code = eval_monty(filestream_fd);
	fclose(filestream_fd);

	return (exit_code);
}
