#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * op_seperater - seperates a string into two strings of the important bits
 * @str: string to be chopped
 * Return: double pointer containing tokens
 */
char **op_seperater(char *str)
{
	char **doubl = NULL;
	char *s = str;
	char *string;
	char *delim = " ";
	int i = 0, j, c;

	while (*s)
	{
		if (*s == *delim)
			i++;
		s++;
	}
	doubl = malloc(sizeof(char *) * (i + 2));
	if (doubl == NULL)
		return (NULL);
	i = 0;
	string = strtok(str, delim);
	while (i < 2)
	{
		if (string == NULL)
			break;
		for (c = 0; string[c] != '\0'; c++)
			if (string[c] == '\n')
				string[c] = '\0';
		doubl[i] = malloc(sizeof(char) * strlen(string) + 1);
		if (doubl[i] == NULL)
		{
			for (j = 0; j <= i; j++)
				free(doubl[j]);
			free(doubl);
			return (NULL);
		}
		strcpy(doubl[i], string);
		i++;
		string = strtok(NULL, delim);
	}
	doubl[i] = NULL;
	return (doubl);
}
