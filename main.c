#include "main.h"
/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: value  of arguments
 * @env: environment variable
 * Return: 0
*/
int main(int argc, char *argv[], char **env)
{
	char *buff = NULL, *prompt = "(£)";
	size_t buff_size = 0;
	ssize_t bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat statbuf;

	(void)argc;
	(void)argv;
while (1 && !from_pipe)
{
if (isatty(STDIN_FILENO) == 0)
from_pipe = true;
write(STDOUT_FILENO, prompt, 2);
bytes = getline(&buff, &buff_size, stdin);
if (bytes == -1)
{
perror("Fatal error (getline)");
free(buff);
exit(EXIT_FAILURE);
}
if (buff[bytes - 1] == '\n')
buff[bytes - 1] = '\0';
wpid = fork();
if (wpid == -1)
{
perror("Fatal error (fork)");
exit(EXIT_FAILURE);
}
if (wpid == 0)
_execute(buff, &statbuf, env);
if (waitpid(wpid, &wstatus, 0) == -1)
{
perror("Fatal error (wait)");
exit(EXIT_FAILURE);
}
}
free(buff);
return (0);
}
/**
 * _execute - execute input files
 * @ac: arguments
 * @statbuf: checks for the status of the buffer
 * @envp: environment param
 * Return: string
*/
int _execute(char *ac, struct stat *statbuf, char **envp)
{
int argc;
char **argv;

argv = split_string(ac, ' ', &argc);
if (!check_file_status(argv[0], statbuf))
{
perror("fatal error (file status)");
exit(EXIT_FAILURE);
}
execve(argv[0], argv, envp);
perror("Fatal error (execve)");
exit(EXIT_FAILURE);
}
/**
 * check_file_status - checks for file
 * @path: shows  directory
 * @statbuf: shows status of buffer
 * Return: true or false
*/
bool check_file_status(char *path, struct stat *statbuf)
{
int stat_update;

stat_update = stat(path, statbuf);

if (stat_update == 0)
return (true);
return (false);
}
/**
 * handle_error -  handles errors from the shell
 * @pid: the process ID of the child process
 */
void handle_error(pid_t pid)
{
if (pid == -1)
{
printf("error");
exit(EXIT_FAILURE);
}
}
