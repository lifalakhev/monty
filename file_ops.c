#include "monty.h"

/**
 * f_open - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void f_open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_f(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = par_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * par_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int par_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fun(opcode, value, line_number, format);
	return (format);
}

/**
 * find_fun - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @linenum: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_fun(char *opcode, char *value, int linenum, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stck},
		{"pall", pstck},
		{"pint", pint_top},
		{"pop", pop_t},
		{"nop", nop},
		{"swap", nodes_swap},
		{"add", nodes_add},
		{"sub", nodes_sub},
		{"div", nodes_div},
		{"mul", nodes_mul},
		{"mod", nodes_mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			get_fun(func_list[i].f, opcode, value, linenum, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, linenum, opcode);
}


/**
 * get_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @linenum: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void get_fun(op_func func, char *op, char *value, int linenum, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, linenum);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, linenum);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, linenum);
		if (format == 1)
			add_que(&node, linenum);
	}
	else
		func(&head, linenum);
}
