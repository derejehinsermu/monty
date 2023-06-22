#include "monty.h"

/**
 *  insert_stack- Pushes an element to the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 * @argument: Argument to be pushed to the stack
 *
 * Return: void
 */
void insert_stack(char *argument, stack_t **stack, unsigned int line_number)
{
	int value;
	
	if (argument == NULL || !is_number(argument))
	{
		_perror(5, line_number);
	}
	value = atoi(argument);
	add_node(stack, value);
}

/**
 * is_number - Checks if a string is a number
 * @str: String to be checked
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *str)
{
	int i;
	
	if (str == NULL || *str == '\0')
		return 0;
	
	i = 0;
	if (str[0] == '-')
		i++;
	
	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

/**
 * display_stack - Prints all the values on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: void
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* Unused parameter */
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
