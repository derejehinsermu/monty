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
	const char *delim = "\n\t ";
	unsigned int line_counter = 0;

	if (str == NULL)
	{
		_perror(4);
		free_all();
                exit(EXIT_FAILURE);
	}
	operator = strtok(str, delim);
	if (operator == NULL)
		return (0);
	while (operator != NULL)
	{
		argument = strtok(NULL, delim);
		if (strcmp(operator, "push") == 0)
		{
			insert_stack(&head, line_counter);
		}
		else if (strcmp(operator, "pall") == 0)
		{
			display_stack(&head, line_counter);
		}
		else if (strcmp(operator, "pint") == 0)
		{
			print_stacktop(&head, line_counter);
		}
		else if (strcmp(operator, "pop") == 0)
		{
			delete_stack(&head, line_counter);
		}
		else if (strcmp(operator, "swap") == 0)
		{
			swap_stack(&head, line_counter);
		}
		else if (strcmp(operator, "add") == 0)
                {
                        add_two(&head, line_counter);
                }
                else if (strcmp(operator, "nop") == 0)
                {
                        do_nothing(&head, line_counter);
                }
	}
	exec_func(argument, &head, line_counter);
	return (0);
}
/**
 * exec_func - find matching function according to provided opcode
 * @operator: holds first token extracted from str above which are opcodes
 * @head: double pointer to head node
 * @line_tracker: keep track of line number
 *
 */
void exec_func(char *operator, stack_t **head, unsigned int line_tracker)
{
	int i;
	int found = 0;

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
		if (strcmp(operator, f_arr[i].opcode) == 0)
		{
			f_arr[i].f(head, line_tracker);
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		_perror(3, line_tracker, operator);
	}
}
/**
 * free_all- free memory allocated to individual nodes
 *
 */

void free_all(void)
{
	stack_t *temp;
	stack_t *head = NULL;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * add_node - add new node at the beginning
 * @head: pointer to head node of list
 * @n: data to be added inside new node
 *
 * Return: address of new element, or NULL if it fails
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		_perror(4);
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;
	if (*head != NULL)
		(*head)->prev = newnode;
	*head = newnode;
	return (*head);
}
