#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

char *intData = NULL;
/**
 * main - entry point for monty interpreter
 * @ac: argument counter
 * @av: argument array
 *
 * Return: 0 or 1
 */
int main(int ac, const char *av[])
{
	char *tok, *cp;
	int a = 0, lineNum = 0;
	FILE *fd;
	size_t n = 0;
	char *line, *code;
	stack_t *h = NULL;
	void (*execute)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file");
                exit(EXIT_FAILURE);		
        }
	lineNum = 0;
	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fd) != -1)
	{
		lineNum++;
		printf("%d", lineNum);
		cp = strdup(line);
		printf("%s\n", cp);
		tok = strtok(cp, " ");
		printf("%s\n", tok);
		code = strdup(tok);
		printf("%s\n", code);
		printf("%s\n", tok);
		intData = strtok(NULL, " ");
		printf("%s\n", intData);
		if (!intData)
			free(intData);
		if (code == NULL)
		{
			continue;
		}
		else if (strcmp(code, "stack") == 0)
		{
			a = 0;
			continue;
		}
		else if (strcmp(code, "queue") == 0)
		{
			a = 1;
			continue;
		}
		if (a == 0)
			execute = getsfunc(code, lineNum);
		(*execute)(&h, lineNum);
	}
	free(line);
	return (0);
}
