#define _GNU_SOURCE
#include "monty.h"

/**
 * access_file - check if file is accessible and can be opened. If not, throw an error
 * @fname: path to the montybytecode file
 */

void access_file(const char *fname)
{
	FILE *fd;

	if (fname == NULL)
	{
		_perror(2, fname);
	}
	if (access(fname, F_OK) != 0)
	{
		_perror(2, fname);
	}
	fd = fopen(fname, "r");
	if (fd == NULL)
	{
		_perror(2, fname);
	}
	else
	{
		open_file(fd);
		fclose(fd);
	}
}

/**
 * open_file - now that we can access it, open and read file
 * @fd: pointer to file descriptor
 */
void open_file(FILE *fd)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread; /* store characters/bytes read */

	/* use getline instead of read; it extracts each line not the whole file */
	while ((nread = getline(&lineptr, &n, fd)) == -1)
	{
		/* replace NULL with head and 0 with linetracker if needed */
		exec_func(lineptr, NULL, 0);/* execute string */
	}
	if (nread == -1 && lineptr != NULL)
	{
		free(lineptr);
	}
}
