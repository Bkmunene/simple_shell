#include "shell.h"
/**
 * _strncpy - copies a string
 * @dest: the destination
 * @src: the source
 * @n: number of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	int i = 0, j;
	char *s = dest;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		 i++;
	}
	if (i < n)
	{
		j = i;

		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 * _strncat - joins two strings
 * @dest: target string to be joined
 * @src: string to join
 * @n: size to be utilised
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 * _strchr - locates a character
 * @s: string in question
 * @c: character in question
 * Return: (s)
 */
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
