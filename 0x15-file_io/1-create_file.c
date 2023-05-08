#include "main.h"

/**
 * create_file - Creates a new file with the specified text content
 *
 * @filename: Name of the file to create
 * @text_content: Text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, rwr;
	size_t num_chars;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (num_chars = 0; text_content[num_chars]; num_chars++)
		;

	rwr = write(fd, text_content, num_chars);
	if (rwr == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}

