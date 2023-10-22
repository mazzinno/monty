#include "monty.h"

/**
 * pr_char - Print the Ascii values.
 * @stacks: Pointer to a pointer pointing to top node of the stack.
 * @number_ofline: the line number of the opcode.
 */
void pr_char(stack_t **stacks, unsigned int number_ofline)
{
	int ascii;

	if (stacks == NULL || *stacks == NULL)
		str_err(11, number_ofline);

	ascii = (*stacks)->n;
	if (ascii < 0 || ascii > 127)
		str_err(10, number_ofline);
	printf("%c\n", ascii);
}

/**
 * pr_str - Print a strings.
 * @stacks: Pointer to a pointer pointing to top node.
 * @n: the line number of of the opcode.
 */
void pr_str(stack_t **stacks, __attribute__((unused))unsigned int n)
{
	int ascii;
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stacks;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot - Rotates the first node .
 * @stacks: Pointer to a pointer pointing to top node of the stack.
 * @n: the line number of the opcode.
 */
void rot(stack_t **stacks, __attribute__((unused))unsigned int n)
{
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		return;

	tmp = *stacks;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stacks;
	(*stacks)->prev = tmp;
	*stacks = (*stacks)->next;
	(*stacks)->prev->next = NULL;
	(*stacks)->prev = NULL;
}


/**
 * rotn - Rotates the last node .
 * @stacks: Pointer to a pointer pointing to top node.
 * @n: the line number of of the opcode.
 */
void rotn(stack_t **stacks, __attribute__((unused))unsigned int n)
{
	stack_t *tmp;

	if (stacks == NULL || *stacks == NULL || (*stacks)->next == NULL)
		return;

	tmp = *stacks;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stacks;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stacks)->prev = tmp;
	(*stacks) = tmp;
}
