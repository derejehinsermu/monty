#include "monty.h"

/**
 * delete_stack - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: void
 */
void delete_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		_perror(7, line_number);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
