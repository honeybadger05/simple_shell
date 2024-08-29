#include "shell.h"

/**
 * _strtok - Tokenizes a string using delimiters
 *
 * @input: The string to be tokenized
 * @delim: The delimiter
 * Return: A pointer to the next token or NULL if there are no tokens left
 */

char *_strtok(char *input, const char *delim)
{
static char *tracker; /* Tracks last input location between calls */
char *token;

if (input != NULL)
	tracker = input; /* Initialize tracker to input string */

/* Check if tracker is NULL or points to a delimiter at the begining */
while ((tracker != NULL) && (_strchr(delim, *tracker) != NULL) &&
(*tracker != '\0'))
	tracker++;
/* Start saving the current token */
token = tracker;

if (tracker == NULL || *tracker == '\0')
	return (NULL); /* No more tokens left */

/* Locate the end of the token */
while (*tracker != '\0')
{
	if (_strchr(delim, *tracker) != NULL)
	{
		/* Delimiter has been found */
		*tracker = '\0'; /* Terminate the current token */
		tracker++; /* Move to the next character after the delimiter */
		return (token);
	}
	tracker++;
}

/* Check if the end of the string has been reached */
if (*tracker == '\0')
{
	tracker = NULL; /* If there are no more tokens, reset tracker */
	return (token); /* Return the final token */
}
return (NULL); /* If there are no more tokens, return NULL */
}
