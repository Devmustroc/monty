#include "monty.h"

/**
 * run - run's specified function
 * @cmd: data to pass to function
 */
void run(cmd_t *cmd)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"sub", sub},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(cmd->op, funcs[i].opcode) == 0)
		{
			funcs[i].f(cmd);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", cmd->line_number, cmd->op);
	exit(EXIT_FAILURE);
}
