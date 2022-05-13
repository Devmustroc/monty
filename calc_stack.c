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
/**
 * divide - divides second top element of the stack with the first top element
 * @cmd: aget variables from command struct
 */
void divide(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int diff;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	node_1 = *h;
	node_2 = (*h)->next;

	if (node_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	diff = node_2->n / node_1->n;
	node_2->n = diff;
	pop(cmd);
}
/**
 * mul - multiplies the second top element of the stack
 * with the first top element.
 * @cmd: get variables from command struct
 */
void mul(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int result;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf("L%d: can't mul, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	result = node_2->n * node_1->n;
	node_2->n = result;

	pop(cmd);
}
/**
 * mod - get the rest of the division of the second
 * with top element with the first top.
 * @cmd: get variables from command struct
 */
void mod(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int reminder;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	if (node_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	reminder = node_2->n % node_1->n;
	node_2->n = reminder;

	pop(cmd);
}
