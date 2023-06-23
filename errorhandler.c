#include "monty.h"

/**
 * _perror -print error to stderr
 * @error_num: number for each error
 * (1) User doesn't give any file or more than one argument.
 * (2) Can't open the file.
 * (3) File contains invalid instructions,
 * (4) Can't malloc anymore.
 * (5) If <int> isn't an integer or no argument is given to push.
 * (6) If the stack is empty when implementing pint.
 * (7) If the stack is empty when implementing pop.
 * (8) If the stack contains less than two elements when implementing swap.
 * (9) If the stack contains less than two elements when implementing add.
 * (10)
 */
void _perror(int error_num, ...)
{
	va_list ap;

	va_start(ap, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(ap, const char *));
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(ap, int),
					va_arg(ap, const char *));
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ap, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ap, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ap, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(ap, int));
			break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(ap, int));
			break;
		/*case 10:
			* printf();
			* break;*/
	}
	free_all();
	va_end(ap);
	exit(EXIT_FAILURE);
}
