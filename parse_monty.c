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
	stack_t *stack = NULL;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1) /* read line from file*/
	{
		line_number++;
		op_tokens = op_seperater(line);  /* separate line into tokens */
		if (op_tokens == NULL)  /* if line is delims or empty continue */
		{
			if (line_is_space(line, DELIMS))
				continue;
			free_stack(&stack); /* return malloc failed error next but > 40 */
		}
		else if (op_tokens[0][0] == '#') /* if line is comments  */
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_tokens[0]);
		if (op_func == NULL)  /* if op_token[0] is not valid command */
		{
			free_stack(&stack);
			exit_code = unknown_instruct(line_number, op_tokens[0]);
			free_tokens();
			break;
		}
		op_func(&stack, line_number);  /* run valid command */
		if (strcmp(op_tokens[0], "FAIL") == 0)
			break;
		free_tokens();
	}
	free_stack(&stack), free(line);
	return (exit_code);
}

/**
 * free_tokens - frees the tokens in the lines read from bytecode file.
 *
 * Return: no return value.
 */
void free_tokens(void)
{
	size_t i;

	if (op_tokens == NULL)
		return;

	for (i = 0; op_tokens[i]; i++)
		free(op_tokens[i]);
	free(op_tokens);
}

/**
 * line_is_space - checks if the character is a whitespace char or not
 * @line: a pointer to the line read from filestream
 * @delims: a pointer to a string of delimeters
 *
 * Return: 1 if char in line are space characters or 0 if not.
 */
int line_is_space(char *line, char *delims)
{
	int alpha, bravo;

	alpha = bravo = 0;

	for (alpha = 0; line[alpha]; alpha++)
	{
		for (bravo = 0; delims[bravo]; bravo++)
		{
			if (line[alpha] == delims[bravo])
			break;
		}
		if (delims[bravo] == '\0')
			return (0);
	}
	return (1);
}
