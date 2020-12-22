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
	stack_t *stack = NULL;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		printf("Line number: %d\t", line_number);
		/* break the line into tokens */
		/* op_tokens = strtok(line, DELIMS); */
		op_tokens = op_seperater(line);
		printf("Retrieved line of length %lu : %s\n", read, line);
		/* if the first token is an op_function */
		for (i = 0; *(op_tokens + i); i++)
		{
			printf(" ---> %s\n", *(op_tokens + i));
		}
		/* if op_token has no match and if there is a match */
		printf("What had happened?!\n");
		op_func = get_op_func(op_tokens[0]);
		printf("Let's do this %s\n", *op_tokens);
		if (op_func == NULL)
		{
			free_stack(stack);
			/* free token */
			break;
		}
		op_func(&stack, line_number);
		printf("I'm the captain now!\n");
		/*   strcpm(op_token[0] = ) */
		/* if get_op_func(op_tokens[0]) */
		/* free tokens  */
	}
	free_stack(stack);
	free(line);
	return (exit_code);
}
