#include "monty.h"

/**
 * erro - Prints appropiate error messages determined by their error code.
 * @error_co: The error codes are :
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => this When the program is unable to malloc more memory.
 * (5) => this When the parameter passed to the instruction "push" is not an int.
 * (6) => this When the stack it empty for pint.
 * (7) => this When the stack it empty for pop.
 * (8) => this When stack is too short for operation.
 */
void erro(int error_co, ...)
{
	va_list ag;
	char *opt;
	int li_num;

	va_start(ag, error_co);
	switch (error_co)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			opt = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", li_num, opt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_erro - handles other errors.
 * @error_co: The error codes are:
 * (6) => this When the stack it empty for pint.
 * (7) => this When the stack it empty for pop.
 * (8) => this When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_erro(int error_co, ...)
{
	va_list ag;
	char *opt;
	int li_num;

	va_start(ag, error_co);
	switch (error_co)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			li_num = va_arg(ag, unsigned int);
			opt = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", li_num, opt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_err - handles errors.
 * @error_co: The error codes are :
 * (10) ~> ehen the number inside a node is outside ASCII bounds.
 * (11) ~> when the stack is empty.
 */
void str_err(int error_co, ...)
{
	va_list ag;
	int li_num;

	va_start(ag, error_co);
	li_num = va_arg(ag, int);
	switch (error_co)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", li_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", li_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
