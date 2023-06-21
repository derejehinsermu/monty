#include "monty.h"

/**
 * tokenize - creates tokens from input
 * @str: pointer to string to be tokenized; contains bytecode
 *
 * Return: always 0 on success
 */
int tokenize(char *str)
{
	char *operator, *argument;
	stack_t *head = NULL;
	const char *delim = "\n ";
	unsigned int line_counter = 0;

	if (str == NULL)
	{
		/* string is empty, error */
	}

	operator = strtok(str, delim);
	if (operator == NULL)
	{
		return (NULL);/* error */
	}
	while (operator != NULL)
	{
		line_counter++;
		argument = strtok(NULL, delim); /* as is */
	}
	line_counter++;

	exec_func(operator, argument, &head, line_counter);

	return (0);
}

/**
 * exec_func - find matching function acc to provided opcode and call e function
 * @operator: holds first token extracted from str above which are opcodes
 * @head: double pointer to head node
 * @line_tracker: keep track of line number
 *
 */
void exec_func(char *operator, stack_t **head, unsigned int line_tracker)
{
	int i;
	int found = 0; /* zero for false or no match yet */

	instruction_t f_arr[] = {
		{"push", insert_stack},
		{"pall", display_stack},
		{"pint", print_stacktop},
		{"pop", delete_stack},
		{"swap", swap_stack},
		{"add", add_two},
		{"nop", do_nothing},
		{NULL, NULL},
	};

	for (i = 0; f_arr[i].opcode != NULL; i++)
	{
		if(strcmp(operator, f_arr[i].opcode) == 0) /*found function */
		{
			f_arr[i].f(head, line_tracker);
			found = 1;
		}
	}
	if (found == 0) /* no match found */
	{
		/* invalid opcode, error*/
	}
}
