#include "monty.h"
stack_t *head = NULL;

/**
 * main - the entry point to fun
 * @argc: arguments counts
 * @argv: list of the arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_exactfile(argv[1]);
	freenodes();
	return (0);
}
