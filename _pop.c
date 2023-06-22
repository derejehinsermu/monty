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

	if (*stack == NULL || stack == NULL)
	{
		_perror(7, line_number);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap_stack - swap the top two elements of a stack
 * @stack: double pointer to head
 * @line_number: Line number in the file
 *
 * Return: void
 */
void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || stack == NULL)
	{
		_perror(8, line_number);
	}
	temp =(*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * add_two - add top two elements of a stack
 * @stack: double pointer to head
 * @line_number: Line number in the file
 *
 * Return: void
 */
void add_two(stack_t **stack, unsigned int line_number)
{
	int add;
	if (stack == NULL || *stack == NULL)
	{
		_perror(9, line_number);
	}
	(*stack) = (*stack)->next;
	add = (*stack)->prev->n + (*stack)->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * do_nothing - do nothing
 * @stack: double pointer to head of node
 * @line_number: Line number in the file
 *
 * Return: void
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
	

