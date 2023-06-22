#include "monty.h"

/**
 * print_stacktop - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: void
 */
void print_stacktop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		_perror(6, line_number);
	}
	printf("%d\n", (*stack)->n);
}

