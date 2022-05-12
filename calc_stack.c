#include "monty.h"

/**
 * add - add the top two elements of the stack
 *
 * @cmd: get data from command struct
 */

void add(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int sum = 0;

	if (cmd == NULL || h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	sum = node_1->n + node_2->n;
	node_2->n = sum;

	pop(cmd);
}
/**
 * sub - substracts top element of the stack from the secound top.
 * @cmd: get variables from command struct
 */
void sub(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int diff = 0;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	diff = node_2->n - node_1->n;
	node_2->n = diff;

	pop(cmd);
}
