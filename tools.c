#include "monty.h"

/**
 * open_f - opens the file
 * @file_nam: the file namepath
 * Return: void
 */

void open_f(char *file_nam)
{
	FILE *fd = fopen(file_nam, "r");

	if (file_nam == NULL || fd == NULL)
		erro(2, file_nam);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads the file
 * @fd: pointer to file 
 * Return: void
 */

void read_f(FILE *fd)
{
	int number_ofline, format = 0;
	char *buffer = NULL;
	size_t leng = 0;

	for (number_ofline = 1; getline(&buffer, &leng, fd) != -1; number_ofline++)
	{
		format = par_line(buffer, number_ofline, format);
	}
	free(buffer);
}


/**
 * par_line - Separates each line 
 * @buffer: lines from the file
 * @number_ofline: the line numbers
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if stack. 1 if queue.
 */

int par_line(char *buffer, int number_ofline, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		erro(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_f(opcode, value, number_ofline, format);
	return (format);
}

/**
 * find_f - find the function for the opcode
 * @opcode: opcode
 * @value: arguments of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @n: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_f(char *opcode, char *value, int n, int format)
{
	int j;
	int fla;

	instruction_t func_list[] = {
		{"push", add},
		{"pall", pr_stack},
		{"pint", pr_top},
		{"pop", toppop},/****/
		{"nop", not},
		{"swap", sw_nodes},
		{"add", add_n},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pr_char},
		{"pstr", pr_str},
		{"rotl", rotn},
		{"rotr", rot},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fla = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_list[j].opcode) == 0)
		{
			call_f(func_list[j].f, opcode, value, n, format);
			fla = 0;
		}
	}
	if (fla == 1)
		erro(3, n, opcode);
	
}


/**
 * call_f - Calls the function.
 * @fun: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @n: line number.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_f(op_func fun, char *op, char *val, int n, int format)
{
	stack_t *node;
	int fla;
	int j;

	fla = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fla = -1;
		}
		if (val == NULL)
			erro(5, n);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				erro(5, n);
		}
		node = crea_node(atoi(val) * fla);
		if (format == 0)
			fun(&node, n);
		if (format == 1)
			add_queue(&node, n);
	}
	else
		fun(&head, n);
}
