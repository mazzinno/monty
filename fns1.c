#include "monty.h"
/**
 * h_add - adds top two elements
 * @head: head.. stack
 * @counter: # line
 * Return: no R
*/
void h_add(stack_t **head, unsigned int counter)
{
	stack_t *j;
	int len = 0, aux;

	j = *head;
	while (j)
	{
		j = j->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	j = *head;
	aux = j->n + j->next->n;
	j->next->n = aux;
	*head = j->next;
	free(j);
}
/**
 * addnode - add node to head.
 * @head: head.. stack
 * @n: value
 * Return: no R
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
* execute - executes opcode
* @stack: head linked list.. stack
* @counter: line.. counter
* @file: poiner to monty
* @content: line of content
* Return: no R
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", h_push}, {"pall", h_pall}, {"pint", h_pint},
				{"pop", h_pop},
				{"swap", h_swap},
				{"add", h_add},
				{"nop", h_nop},
				{"sub", h_sub},
				{"div", h_div},
				{"mul", h_mul},
				{"mod", h_mod},
				{"pchar", h_pchar},
				{"pstr", h_pstr},
				{"rotl", h_rotl},
				{"rotr", h_rotr},
				{"queue", h_queue},
				{"stack", h_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
/**
 * h_div - divides top two elements.
 * @head: head.. stack
 * @counter: # line
 * Return: no R
*/
void h_div(stack_t **head, unsigned int counter)
{
	stack_t *j;
	int len = 0, aux;

	j = *head;
	while (j)
	{
		j = j->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack is short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	j = *head;
	if (j->n == 0)
	{
		fprintf(stderr, "L%d: division by 0\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = j->next->n / j->n;
	j->next->n = aux;
	*head = j->next;
	free(j);
}
/**
* free_stack - free doubly linked list
* @head: head.. stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
