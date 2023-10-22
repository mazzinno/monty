#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry element
 * @argc: arguments who count
 * @argv: list of arguments we have
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_nodes();
	return (0);
}

/**
 * crea_node - Creates a node we need.
 * @n: Number that go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *crea_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		erro(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_queue - Adds a node to the queue.
 * @new_nod: Pointer to the new node.
 * @n: number of line of the opcode.
 */
void add_queue(stack_t **new_nod, __attribute__((unused))unsigned int n)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_nod;
	(*new_nod)->prev = tmp;

}
