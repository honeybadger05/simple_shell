#include "shell.h"

/**
 * _strcmp - Compares 2 strings using a loop.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Negative, positive, or zero value if s1 is
 * less than, greater than, or equal to s2.
 */

int _strcmp(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s1 == *s2)
{
	s1++;
	s2++;
}
return (*s1 - *s2);
}




/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to a string.
 *
 * Return: Length of the string.
 */

int _strlen(const char *s)
{
int length;

length = 0;

while (*s != '\0')
{
	length++;
	s++;
}
return (length);
}




/**
 * _strchr - Finds the first occurrence of characters within strings
 * @s: String to be searched
 * @c: Character to be found
 *
 * Return: Pointer to the first occurrence of c in
 * s, or NULL for unfound characters
 */

const char *_strchr(const char *s, int c)
{
while (*s != '\0')
{
	if (*s == c)
	{
		return (s);
	}
	s++;
}
if (c == '\0')
	return (s);

return (NULL);
}








/**
 * _strcpy - Copies the string pointed to by src to dest.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
char *initial_dest = dest;

while ((*dest = *src) != '\0')
{
	dest++;
	src++;
}
return (initial_dest);
}









/**
 * _strdup - Duplicates a string
 * @s: String to be duplicated
 *
 * Return: Pointer to the duplicated string
 * or NULL for failed memory allocation
 */

char *_strdup(const char *s)
{

int length;
char *duplicate;

if (s == NULL)
	return (NULL);

length = strlen(s) + 1;
duplicate = (char *)malloc(length);

if (duplicate == NULL)
	return (NULL);

strcpy(duplicate, s);

return (duplicate);
}
