#include "monty.h"

/**
 * main - the monty intepreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		_perror(1);
		free_all();
                exit(EXIT_FAILURE);
	}
	access_file(argv[1]);
	free_all();

	return (0);
}
