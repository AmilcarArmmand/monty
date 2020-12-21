#include "monty.h"

/**
 * parse_monty - the entry point of the Monty Bytecode Interpreter
 * @fp: a pointer to the file stream of a bytecode file
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on error.
 */
int parse_monty(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int exit_code = EXIT_SUCCESS;
	unsigned int line_number = 0;
	char *op_tokens = NULL;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		printf("Line number: %d\t", line_number);
		/* break the line into tokens */
		op_tokens = strtok(line, DELIMS);
		op_tokens = strtok(line, DELIMS);

		printf("Retrieved line of length %lu : %s\n", read, line);
		/* if the first token is an op_function */
		printf(" ---> %s\n", op_tokens);
		/* if get_op_func(op_tokens[0]) */
	}

	free(line);
	return (exit_code);
}
