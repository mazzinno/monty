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
		err(2, file_nam);

	read_file(fd);
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

	for (number_ofline = 1; getline(&buffer, &len, fd) != -1; number_ofline++)
	{
		format = parse_line(buffer, number_ofline, format);
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
	char *opco, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opco = strtok(buffer, delim);
	if (opco == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opco, "stack") == 0)
		return (0);
	if (strcmp(opco, "queue") == 0)
		return (1);

	find_func(opco, value, number_ofline, format);
	return (format);
}

/**
 * find_f - find the function for the opcode
 * @opco: opcode
 * @value: arguments of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @n: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_f(char *opco, char *value, int n, int format)
{
	int j;
	int fla;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opco[0] == '#')
		return;

	for (fla = 1, j = 0; func_list[j].opco != NULL; j++)
	{
		if (strcmp(opco, func_list[j].opco) == 0)
		{
			call_fun(func_list[j].f, opco, value, n, format);
			fla = 0;
		}
	}
	if (fla == 1)
		err(3, n, opco);
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
			err(5, n);
		for (j = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[j]) == 0)
				err(5, n);
		}
		node = create_node(atoi(val) * fla);
		if (format == 0)
			func(&node, n);
		if (format == 1)
			add_to_queue(&node, n);
	}
	else
		func(&head, n);
}
