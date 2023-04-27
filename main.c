#include "shell.h"
#include "execmd.c"
/**
 * main - point of access to our code
 * @ac: number of argument
 * @argv: values in argument
 * Return: 0 when successfully executed and 1 when erratic
 */
int main(int ac, char **argv)
{
	char *prompt = "($)";
	char *line_ptr = NULL, *line_ptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t n_value;
	const char *delim = " \n";
	int i, num_tokens = 0;

	(void)ac;
while (1)
{
printf("%s", prompt);
n_value = getline(&line_ptr, &n, stdin);
if (n_value == -1)
{
printf("Exiting shell...\n");
return (-1);
}
		line_ptr_copy = malloc(sizeof(char) * n_value);
		if (line_ptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(line_ptr_copy, line_ptr);
		token = strtok(line_ptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(line_ptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(line_ptr_copy);
	free(line_ptr);

	return (0);
}
