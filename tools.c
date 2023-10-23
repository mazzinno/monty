#include "monty.h"
/**
 * open_exactfile - iotrtfgdg opens same file
 * @file_name: the file namepath
 * Return: void
 */

void open_exactfile(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_exactfile(fd);
	fclose(fd);
}


/**
 * read_exactfile - it reads the file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_exactfile(FILE *fd)
{
	int line_number; 
	int format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}
