#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file of operations*/
void open_f(char *file_nam);
int par_line(char *buffer, int number_ofline, int format);
void read_f(FILE *);
int len_chars(FILE *);
void find_f(char *, char *, int, int);

/*Stack of operations*/
stack_t *crea_node(int n);
void free_nodes(void); /*****/
void pr_stack(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_f(op_func, char *, char *, int, int);

void pr_top(stack_t **, unsigned int);
void toppop(stack_t **, unsigned int);
void not(stack_t **, unsigned int); /**why not shining*/
void sw_nodes(stack_t **, unsigned int); 

/*Math operations that related to the nodes*/
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/*fonctions String operations*/
void pr_char(stack_t **, unsigned int);
void pr_str(stack_t **, unsigned int);
void rot(stack_t **, unsigned int);

/*finction error hanlding*/
void erro(int error_code, ...);
void more_erro(int error_code, ...);
void str_err(int error_code, ...);
void rotn(stack_t **, unsigned int);

#endif
