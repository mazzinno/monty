#include "monty.h"

/**
 * not - nothing.
 * @stacks: Pointer to a pointer pointing to top node.
 * @number_ofline: the line number of the opcode.
 */
void not(stack_t **stacks, unsigned int number_ofline)
{
	(void)stacks;
	(void)number_ofline;
}


/**
 * sw_nodes - Swaps to the top two elements.
 * @stacks: Pointer to a pointer pointing to top node.
 * @number_ofline: the line number of the opcode.
 */
void sw_nodes(stack_t **stacks, unsigned int number_ofline)
{
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		more_erro(8, number_ofline, "swap");
	tmp = (*stacks)->next;
	(*stacks)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stacks;
	tmp->next = *stacks;
	(*stacks)->prev = tmp;
	tmp->prev = NULL;
	*stacks = tmp;
}

/**
 * add_n - Adds the top two elements.
 * @stacks: Pointer to a pointer pointing to top node .
 * @number_ofline: the line number of the opcode.
 */
void add_n(stack_t **stacks, unsigned int number_ofline)
{
	int summ;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		more_erro(8, number_ofline, "add");

	(*stacks) = (*stacks)->next;
	summ = (*stacks)->n + (*stacks)->prev->n;
	(*stacks)->n = summ;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}


/**
 * sub - Adds the top two elements .
 * @stacks: Pointer to a pointer pointing to top node.
 * @number_ofline: the line number of the opcode.
 */
void sub(stack_t **stacks, unsigned int number_ofline)
{
	int summ;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)

		more_erro(8, number_ofline, "sub");


	(*stacks) = (*stacks)->next;
	summ = (*stacks)->n - (*stacks)->prev->n;
	(*stacks)->n = summ;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}


/**
 * div - Adds the top two elements.
 * @stacks: Pointer to a pointer pointing to top node .
 * @number_ofline: the line number  of the opcode.
 */
void div(stack_t **stacks, unsigned int number_ofline)
{
	int summ;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		more_erro(8, number_ofline, "div");

	if ((*stacks)->n == 0)
		more_erro(9, number_ofline);
	(*stacks) = (*stacks)->next;
	summ = (*stacks)->n / (*stacks)->prev->n;
	(*stacks)->n = summ;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}
