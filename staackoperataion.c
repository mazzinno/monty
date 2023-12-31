#include "monty.h"

/**
 * mul_nodes - Aaa it adddds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sumo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sumo = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sumo;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
