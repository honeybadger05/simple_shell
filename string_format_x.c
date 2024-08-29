#include "shell.h"

/**
 * chrstr - Locate the first occurrence of a character in a string.
 * @string: The string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *chrstr(const char *string, int c)
{
	while (*string != '\0')
	{
		if (*string == c)
		{
			return ((char *)string);
		}
		string++;
	}
	if (c == '\0')
	{
		return ((char *)string);
	}
	return (NULL);
}

/**
 * cmpnstr - Compare the first n characters of two strings.
 * @string1: The first string to be compared.
 * @string2: The second string to be compared.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if the first n
 *         characters of strg1 are found, respecly,to be less than,to match
 *         or be greater than the first n chars of string2.
 */
int cmpnstr(const char *string1, const char *string2, size_t n)
{
	while (n > 0 && (*string1 != '\0' || *string2 != '\0'))
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}
		string1++;
		string2++;
		n--;
	}
	return (0);
}
