#include "shell.h"
/**
 * _myhistory - displays the history list starting at 0
 * @info: Structure containing arguments.
 *  Return: Always 0
 */
int print_history_list(info_t *info)
{
	if (info == NULL)
	{
		fprintf(stderr, "Error: info is NULL.\n");
		return -1;
	}
	linked_list_t *history_list = info->history;

	if (history_list == NULL)
	{
		fprintf(stderr, "Error: history list is NULL.\n");
		return -1;
	}

	print_list(history_list);

	return 0;
}
/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0
 */
int unset_alias(info_t *info, char *alias_name)
{
	const char EQUAL_SIGN = '=';

	char *equal_sign_position = _strchr(alias_name, EQUAL_SIGN);
	if (equal_sign_position == NULL)
	{
		return 1;
	}

	char original_character = *equal_sign_position;
	*equal_sign_position = '\0';

	int delete_result = delete_node_at_index(&(info->alias),
			get_node_index(info->alias,
				node_starts_with(info->alias, alias_name, -1)));

	equal_sign_position = original_character;
	return (delete_result == 0) ? 0 : 1;
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success
 */
int print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}
/**
 * _myalias - copies the alias builtin
 * @info: Structure containing arguments
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
		{
			set_alias(info, info->argv[i]);
		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
		}
	}
		return (0);
}
