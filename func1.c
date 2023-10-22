#include "monty.h"


/**
 * add - Adds a node stack.
 * @new_nod: Pointer to the new node position.
 * @n: the line number of of the opcode.
 */
void add(stack_t **new_nod, __attribute__((unused))unsigned int n)
{
	stack_t *tmp;

	if (new_nod == NULL || *new_nod == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_nod;
		return;
	}
	tmp = head;
	head = *new_nod;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pr_stack - Adds the node to the stack.
 * @stacks: the pointer to a pointer is pointing to the top node of the stack.
 * @number_ofline: number of lines of the opcode.
 */
void pr_stack(stack_t **stacks, unsigned int number_ofline)
{
	stack_t *tmp;

	(void) number_ofline;
	if (stacks == NULL)
		exit(EXIT_FAILURE);
	tmp = *stacks;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * toppop - Adds a node.
 * @stacks: Pointer to a pointer pointing to top node .
 * @number_ofline: number of the line  of the opcode.
 */
void toppop(stack_t **stacks, unsigned int number_ofline)
{
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL)
		more_erro(7, number_ofline);

	tmp = *stacks;
	*stacks = tmp->next;
	if (*stacks != NULL)
		(*stacks)->prev = NULL;
	free(tmp);
}

/**
 * pr_top - Prints the top node.
 * @stacks: Pointer to a pointer pointing to top node.
 * @number_ofline:  the line number of the opcode.
 */
void pr_top(stack_t **stacks, unsigned int number_ofline)
{
	if (stacks == NULL || *stacks == NULL)
		more_erro(6, number_ofline);
	printf("%d\n", (*stacks)->n);
}
