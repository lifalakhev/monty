#include "monty.h"

/**
 * main - entry point.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_open(argv[1]);
	free_nodes();
	return (0);
}
