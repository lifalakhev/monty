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

void f_open(char *file_name);
int par_line(char *buffer, int line_number, int format);
void read_f(FILE *);
int c_length(FILE *);
void find_fun(char *, char *, int, int);

stack_t *create_node(int n);
void free_nodes(void);
void pstck(stack_t **, unsigned int);
void add_stck(stack_t **, unsigned int);
void add_que(stack_t **, unsigned int);

void get_fun(op_func, char *, char *, int, int);

void pint_top(stack_t **, unsigned int);
void pop_t(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodes_swap(stack_t **, unsigned int);

void nodes_add(stack_t **, unsigned int);
void nodes_sub(stack_t **, unsigned int);
void nodes_div(stack_t **, unsigned int);
void nodes_mul(stack_t **, unsigned int);
void nodes_mod(stack_t **, unsigned int);

void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

void err(int error_code, ...);
void era(int error_code, ...);
void strerr(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
