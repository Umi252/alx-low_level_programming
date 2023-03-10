/**
 * _strcat - Concatenates two strings
 *
 * @dest: The destination string
 * @src: The source string
 *
 * Return: A pointer to the resulting string
 *
 * Description: The _strcat function appends the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end of dest, and then
 * adds a terminating null byte.
 * must have enough space for the result. If dest is not large enough, program
 * behavior is unpredictable;
 * are possible.
 */
char *_strcat(char *dest, char *src)
{

	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);

}

