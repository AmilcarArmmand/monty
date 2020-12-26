#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

char **op_tokens = NULL;

/**
 * main - the entry point of the Monty Bytecode Interpreter
 * @argc: the number of arguments passed to main
 * @argv: pointer to an array of pointers to arguments passed to main
 *
 * Return: (EXIT_SUCCESS) for success or (EXIT_FAILURE) for error
 */
int main(int argc, char **argv)
{
	FILE *fp;
	int exit_code;

	exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		return (usage_error());
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		return (file_open_error(argv[1]));
	}

	exit_code = parse_monty(fp);
	fclose(fp);
	return (exit_code);
}
