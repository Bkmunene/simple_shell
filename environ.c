#include "shell.h"

/**
 * _myenv - displays environment
 * @info: Structure containing arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	list_t *node;

	for (node = info->env; node; node = node->next)
		printf("%s\n", node->str);

	return (0);
}

/**
 * _getenv - fetches the value of environ variable
 * @info: Structure containing arguments
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node;
	char *p;

	for (node = info->env; node; node = node->next)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
	}

	return (NULL);
}

/**
 * _mysetenv - Initialize/modify environment variable
 * @info: Structure containing arguments
 * Return: 0 on success, 1 on failure
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]) != 0)
		return (1);

	return (0);
}

/**
 * _myunsetenv - Removes environment variable
 * @info: Structure of arguments
 * Return: 0 on success, 1 on failure
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (i = 1; i < info->argc; i++)
		if (_unsetenv(info, info->argv[i]) != 0)
			return (1);

	return (0);
}

/**
 * populate_env_list - adds to env linked list
 * @info: Structure containing arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);

	info->env = node;
	return (0);
}

