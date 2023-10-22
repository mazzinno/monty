#include "monty.h"

/**
 * mul - Adds the top two elements.
 * @stacks: Pointer to a pointer pointing to top node.
 * @number_ofline: Interger representing the line number of of the opcode.
 */
void mul(stack_t **stacks, unsigned int number_ofline)
{
	int summ;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		more_erro(8, number_ofline, "mul");

	(*stacks) = (*stacks)->next;
	summ = (*stacks)->n * (*stacks)->prev->n;
	(*stacks)->n = summ;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}


/**
 * mod - Adds the top two elements.
 * @stacks: Pointer to a pointer pointing to top node
 * @number_ofline: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stacks, unsigned int number_ofline)
{
	int summ;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)

		more_erro(8, number_ofline, "mod");


	if ((*stacks)->n == 0)
		more_erro(9, number_ofline);
	(*stacks) = (*stacks)->next;
	summ = (*stacks)->n % (*stacks)->prev->n;
	(*stacks)->n = summ;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}

