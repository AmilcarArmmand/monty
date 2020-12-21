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
	char **op_tokens = NULL;
	int i = 0;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		printf("Line number: %d\t", line_number);
		/* break the line into tokens */
		/* op_tokens = strtok(line, DELIMS); */
		op_tokens = op_seperater(line);
		printf("Retrieved line of length %lu : %s\n", read, line);
		/* if the first toke is an op_function */
		for (i = 0; *(op_tokens + i); i++)
		{
			printf(" ---> %s\n", *(op_tokens + i));
		}
		/*   strcpm(op_token[0] = ) */
		/* if get_op_func(op_tokens[0]) */
	}

	free(line);
	return (exit_code);
}