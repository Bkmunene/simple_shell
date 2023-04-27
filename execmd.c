#include "shell.h"
/**
 * execmd - execute the command with execv
 * @argv: command input
 * Return:void
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
