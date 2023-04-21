#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/*memory buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/*end of memory buffer*/
/*chaining command*/
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3
/*end of chaining command*/
/*number manipulation*/
#define CONVERT_UNSIGNED 2
#define CONVERT_LOWERCASE 1
/*end of number manipulation*/
/*file manipulation*/
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
extern char **environ;
/**
 * struct liststr - singly linked list
 * @str: the listed string
 * @num: the listed number field
 * @next: points to the next node
 */
typedef struct liststr
{
	char *str;
	int num;
	struct liststr *next;
} list_str;
/**
 * struct passinfo - has function arguments that allow fuction prototype
 * of pointer struct
 * @arg:argument strings
 * @argv: value of arguments
 * @path: current command path
 * @argc: number of arguments
 * @line_count: counts the errors
 * @err_num: error code for the problem
 * @linecount_flag: counts the number of input lines when it is activated
 * @fname: file name
 * @env: the environment involved
 * @history: memory of previous env
 * @alias: reference
 * @env_changed: indicates if the env was changed
 * @status: shows the progress of the last executed command
 * @cmd_buf: pointer to the memomry buffer of cmd
 * @cmd_buf_type: type of chain buffer for memory management
 * @histcount: history of line counter
 * @readfd: the directory where the line that is red
 */
typedef struct passinfo
{
	int status, argc, err_num, linecount_flag, env_changed, cmd_buf_type;
	int readfd, histcount;
	unsigned int line_count;
	char *arg, **argv, *path, *fname, **environ, **cmd_buf;
	list_t *env;
	list_t *history;
	list_t *alias;
} cnt;
#define INFO_INIT
{0, 0, 0, 0, 0, 0, 0, 0, 0,\
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
}
/**
 * struct builtin - structure containing strings and related function
 * @func: related function
 * @type: command flag
 */
typedef struct builtin
{
	char *type;
	int (*func)(cnt *);
} builtin_tb;
/*conv.c*/
int is_shell_active(cnt *info);
int delim_conf(char, char *);
int alpha_conf(int);
int convert(char *);

#endif /* HEAD_H */
