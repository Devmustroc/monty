#include "monty.h"

/**
 * parse - parses line of input into tokens
 * @line: input to parse
 * @cmd: sending args to function
 * Return: 0 skip line, 1 continue
 */
int parse(char *line, cmd_t *cmd)
{
	char delims[] = " \t\r\n", *op, *arg;
	int siz;
	unsigned int ln = cmd->line_number;

	if (line == NULL)
		return (0);
	op = strtok(line, delims);
	if (op == NULL || op[0] == '#')
		return (0);
	if (strcmp(op, "stack") == 0)
	{
		*cmd->mode = 0;
		return (0);
	}
	if (strcmp(op, "queue") == 0)
	{
		*cmd->mode = 1;
		return (0);
	}
	if (strcmp(op, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		siz = strlen(arg);
		while (siz--)
		{
			if (siz == 0 && arg[siz] == '-')
				break;
			if (arg[siz] > 57 || arg[siz] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		cmd->arg = atoi(arg);
		cmd->op = op;
		return (1);
	}
	cmd->op = op;
	return (1);
}
