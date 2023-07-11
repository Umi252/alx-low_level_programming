#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename
 * @letters: number of letters printed
 *
 * Return: number of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(*buf) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	nrd = read(fd, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fd);
	free(buf);

	return (nwr);
}

