#include "shell.h"
/**
 * is_interactive - checks if shell is in interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(const info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delimiter - checks if character is a delimiter
 * @c: char in question
 * @delim: delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, const char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * is_alpha - checks for alphabetic character
 * @c: The character in question
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/**
 * str_to_int - converts a string to an integer
 * @s: string in question
 * Return: 0 if no numbers in strin else number
 */
int str_to_int(const char *s)
{
	int i, sign = 1, output = 0;
	size_t len = strlen(s);

	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (isdigit(s[i]))
			output = output * 10 + (s[i] - '0');
		else
			return (0);
	}

	return (output * sign);
}

