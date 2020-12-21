#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Retrieved line of length %lu : %s\n", read, line);
	}

	free(line);
	exit(EXIT_SUCCESS);
}
