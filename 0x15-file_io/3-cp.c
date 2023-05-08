#include "main.h"
#include <stdio.h>

/**
 * check_files - checks if files can be opened
 * @file1: first file descriptor
 * @file2: second file descriptor
 * @filename1: name of first file
 * @filename2: name of second file
 */

void check_files(int file1, int file2, char *filename1, char *filename2)
{
	if (file1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename1);
		exit(98);
	}
	if (file2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename2);
		exit(99);
	}
}

/**
 * main - copies the content of one file to another file
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	int fd1, fd2, rd, wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	check_files(fd1, fd2, argv[1], argv[2]);

	while ((rd = read(fd1, buffer, 1024)) > 0)
	{
		wr = write(fd2, buffer, rd);
		if (wr != rd || wr == -1)
			check_files(-1, fd2, argv[1], argv[2]);
	}

	if (rd == -1)
		check_files(-1, fd2, argv[1], argv[2]);

	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}

	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}

	return (0);
}

