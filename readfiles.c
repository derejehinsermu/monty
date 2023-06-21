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
		/* error opening file */
	}
	if (access(fname, F_OK) != 0)
	{
		/* failure accesing file; error */
	}	
	fd = fopen(fname, "r");
	if (fd == NULL)
	{
		/* error opening */
	}
	else
	{
		open_file(fd);
	}
	fclose(fd);
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
	nread = getline(&lineptr, &n, fd);
	if (nread < 0)
	{
		free(lineptr); /* couldn't read file */
	}
	while (nread != -1)
	{
		/* replace NULL with head and 0 with linetracker if needed */
		exec_func(lineptr, NULL, 0);/* execute string */
	}
	free(lineptr);
}
