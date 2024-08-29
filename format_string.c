#include "shell.h"

/**
 * lenofstr - Get the length of a string.
 * @string: The string to determine the length of.
 *
 * Return: The length of the string.
 */
int lenofstr(char const *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * dupstr - Duplicate a string.
 * @string: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated duplicated string,
 *         or NULL if memory allocation fails.
 */
char *dupstr(const char *string)
{
	int len = lenofstr(string);
	char *new_str = malloc(len + 1);

	if (new_str != NULL)
	{
		int i;

		for (i = 0; i < len; i++)
		{
			new_str[i] = string[i];
		}
		new_str[len] = '\0';
	}

	return (new_str);
}

/**
 * cpynstr - Copy a specified number of characters from one string to another.
 * @dest: The destination buffer to copy to.
 * @src: The source string to copy from.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination buffer.
 */
char *cpynstr(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 * catnstr - Concatenate a specified nums of chars from one string to another.
 * @dest: The destination buffer to concatenate to.
 * @src: The source string to concatenate from.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: A pointer to the destination buffer.
 */
char *catnstr(char *dest, const char *src, size_t n)
{
	size_t dest_len = lenofstr(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}
