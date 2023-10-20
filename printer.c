#include "monty.h"
/**
 * h_pint - prints the top
 * @head: stack
 * @counter: line number
 * Return: no return
*/
void h_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * h_pop - prints the top
 * @head: stack
 * @counter: line number
 * Return: no return
*/
void h_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * h_pstr - prints string starting at the top
 * @head: stack
 * @counter: line number
 * Return: no return
*/
void h_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
 * h_push - add node
 * @head: stack
 * @counter: line number
 * Return: no return
*/
void h_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, fl = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				fl = 1; }
		if (fl == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
  *h_rotl- rotates stack to the top
  *@head: stack
  *@counter: line number
  *Return: no return
 */
void h_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *ax;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	ax = (*head)->next;
	ax->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = ax;
}
