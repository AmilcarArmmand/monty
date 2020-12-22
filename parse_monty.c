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
	int i = 0;
	stack_t *stack = NULL;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		/* break the line into tokens */
		/* op_tokens = strtok(line, DELIMS); */
		op_tokens = op_seperater(line);
		/* if op_token has no match and if there is a match */
		op_func = get_op_func(op_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(stack);
			for (i = 0; op_tokens[i]; i++)
				free(op_tokens[i]);
			free(op_tokens);
			break;
		}
		op_func(&stack, line_number);
		/*   strcpm(op_token[0] = ) */
		/* if get_op_func(op_tokens[0]) */
		/* free tokens  */
		for (i = 0; op_tokens[i]; i++)
			free(op_tokens[i]);
		free(op_tokens);
	}
	free_stack(stack);
	free(line);
	return (exit_code);
}
