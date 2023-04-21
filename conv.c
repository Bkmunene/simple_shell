#include "head.h"
/**
 * is_shell_active - checks if the current process is a shell
 * @info: pointer to a struct containing information about the shell
 *
 * Returns: 1 if the current process is a shell, 0 otherwise
 */
int is_shell_active(cnt *info)
{
	if (!isatty(STDIN_FILENO))
	{
		/* Not connected to a terminal*/
		return (0);
	}
	if (info->readfd > 2)
	{
		return (0);
	}
	return (1);
}
/**
 * delim_conf - confirms a delimiter
 * @del: delimeter
 * @c: character in question
 * Return: 1 for true and 0 for false
 */
int delim_conf(char c, char *del)
{
	while (*del)
	{
		if (*del++ == c)
		{
			return (1);
		}
	}
}
/**
 * alpha_conf - confirms if character is alphabet
 * @c:character in question
 * Return: 1 for alphabet or 0 for anything else
 */
int alpha_conf(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * convert - changes to number
 * @s: string in question
 * Return: 0 when erratic or number
 */
int convert(char *s)
{
	int sign = 1;
	unsigned int result = 0;

	while (*s)
	{
		if (*s == '-')
			sign = -1;
		else if (*s >= '0' && *s <= '9')
		{
			result *= 10;
			result += (*s - '0');
		}
		else if (result > 0)
			break;
		s++;
	}
	return (sign * result);
}
