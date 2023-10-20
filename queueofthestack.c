#include "monty.h"
/**
 * h_queue - prints top
 * @head: head.. stack
 * @counter: # line
 * Return: no R
*/
void h_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to end stack
 * @n: value
 * @head: head.. stack
 * Return: no R
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
/**
 * h_stack - prints top
 * @head: head.. stack
 * @counter: # line
 * Return: no R
*/
void h_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
