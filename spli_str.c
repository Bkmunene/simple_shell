#include "main.h"
/**
 * split_string - a function that takes in string and splits it
 * @string: the string in question
 * @delimiter: The character delimiter used to split the string.
 * @count: determines the length
 * Return: the split string result
 */
char **split_string(char *string, char delimiter, int *count)
{
int i, j, len, start;
char **result;

len = strlen(string);
*count = 0;

for (i = 0; i < len; i++)
{
if (string[i] == delimiter)
{
(*count)++;
}
}
(*count)++;
result = (char **)malloc((*count) * sizeof(char *));
if (result == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}

j = 0;
start = 0;
for (i = 0; i < len; i++)
{
if (string[i] == delimiter)
{
string[i] = '\0';
result[j] = &string[start];
j++;
start = i + 1;
}
}
result[j] = &string[start];
return (result);
}

