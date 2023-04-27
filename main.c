#include "shell.h"
/**
 * main - point of access to our code
 * @ac: number of argument
 * @argv: values in argument
 * Return: 0 when successfully executed and 1 when erratic
 */

void print_prompt(const char *prompt);
ssize_t read_input(char **line_ptr, size_t *n);
char **tokenize_input(char *line_ptr, const char *delim, int *num_tokens);
void free_tokens(char **tokens, int num_tokens);
void execute_command(char **tokens);

int main(int ac, char **argv)
{
	const char *prompt = "(ODIN $ )";
	char *line_ptr = NULL;
	size_t n = 0;
	ssize_t n_value;
	const char *delim = " \n";
	int num_tokens = 0;

	(void)ac;
	while (1)
	{
		print_prompt(prompt);
		n_value = read_input(&line_ptr, &n);
		if (n_value == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}
		argv = tokenize_input(line_ptr, delim, &num_tokens);
		execute_command(argv);
		free_tokens(argv, num_tokens);
		free(line_ptr);
		line_ptr = NULL;
	}
	return (0);
}
/**
 * print_promp - prints prompter when shell is initialised
 * @prompt: the prompt to be printed
 * Return: void
 */
void print_prompt(const char *prompt)
{
	printf("%s", prompt);
}
/**
 * read_input - reads what the user types
 * @line_ptr:  the line to be read
 * @n: size of line
 * Return: string
 */
ssize_t read_input(char **line_ptr, size_t *n)
{
	return (getline(line_ptr, n, stdin));
}
/**
 * tokenize_input - converts the input into string
 * @line_ptr:line to be read from input
 * @delim: a delimeter
 * @num_tokens: size of the string
 * Return: string
 */
char **tokenize_input(char *line_ptr, const char *delim, int *num_tokens)
{
	char *line_ptr_copy, *token;
	int i;
	char **tokens;

	line_ptr_copy = strdup(line_ptr);
	if (line_ptr_copy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
	}
	token = strtok(line_ptr, delim);
	while (token != NULL)
	{
		(*num_tokens)++;
		token = strtok(NULL, delim);
	}
	(*num_tokens)++;
	tokens = malloc(sizeof(char *) * (*num_tokens));
	if (tokens == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
	}
	token = strtok(line_ptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("tsh: memory allocation error");
			exit(-1);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	free(line_ptr_copy);
	return (tokens);
}
/**
 * free_token - clears the memory
 * @tokens: pointer to memory
 * @num_tokens: size of memory
 * Return: void
 */
void free_tokens(char **tokens, int num_tokens)
{
	int i;

	for (i = 0; i < num_tokens; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
/**
 * execute_command - calls a command to execute function
 * @argv: argument
 */
void execute_command(char **argv)
{
	execmd(argv);
}

