#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
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
/* Instructions */

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

void insert_stack(stack_t **stack, unsigned int line_number);
int is_number(const char *str);
/* disply stack*/
void display_stack(stack_t **stack, unsigned int line_number);
/* print stack from top*/
void print_stacktop(stack_t **head, unsigned int line_number);
/*delete stack */
void delete_stack(stack_t **head, unsigned int line_number);
/*  read files */
void access_file(const char *fname);
void open_file(FILE *fd);
/* parse and execute */
void exec_func(char *operator, stack_t **head, unsigned int line_tracker);
int tokenize(char *str);
void free_all(void);
stack_t *add_node(stack_t **head, const int n);
/* main */
int main(int argc, char *argv[]);
/* handle errors */
void _perror(int error_num, ...);
/* operatins */
void do_nothing(stack_t **stack, unsigned int line_number);
void add_two(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
