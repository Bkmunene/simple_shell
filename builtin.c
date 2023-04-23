#include "shell.h"

/**
 * _myexit - terminates the shell
 * @info: Structure containing arguments.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
    if (info->argv[1])
    {
        int exit_code = _erratoi(info->argv[1]);
        if (exit_code == -1)
        {
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (2);
        }
        return (exit_code);
    }
    return (2);
}

/**
 * _mycd - changes the current directory
 * @info: Structure containing arguments
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
    char buffer[PATH_MAX], *dir;
    int chdir_ret;

    if (!getcwd(buffer, PATH_MAX))
        _puts("TODO: >>getcwd failure emsg here<<\n");

    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        dir = _getenv(info, "OLDPWD=");
        if (!dir)
        {
            _puts(buffer);
            _putchar('\n');
            return (1);
        }
        _puts(dir), _putchar('\n');
        chdir_ret = chdir(dir);
    }
    else
    {
        chdir_ret = chdir(info->argv[1]);
        dir = info->argv[1];
    }

    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(dir), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, PATH_MAX));
    }

    return (0);
}

/**
 * _myhelp - prints help message
 * @info: Structure containing arguments
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    _puts("help command not implemented yet\n");
    if (0)
        _puts(*arg_array);
    return (0);
}

