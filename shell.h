#ifndef _SHELL_H_
#define _SHELL_H_
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
} list_t;
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
	int status;
	int argc;
	int err_num;
	int linecount_flag;
	int env_changed;
	int cmd_buf_type;
	int histcount;
	int readfd;
       	unsigned int line_count;
	char *arg;
	char **argv;
	char *path;
	char *fname;
	char **environ;
	char **cmd_buf;
	list_t *env;
	list_t *history;
	list_t *alias;
} info_t;
#define INFO_INIT {\
	0, /* status */ \
	0,/* argc */ \
	0,/* err_num */ \
	0,/* linecount_flag */ \
	0,/* env_changed */ \
	0,/* cmd_buf_type */ \
	0,/* histcount */ \
	0,/* readfd */ \
	0,/* line_count */ \
	NULL,/* arg */ \
       	NULL,/* argv */ \
       	NULL,/* path */ \
       	NULL,/* fname */ \
       	NULL,/* environ */ \
       	NULL,/* cmd_buf */ \
       	NULL,/* env */ \
       	NULL,/* history */ \
       	NULL/* alias */ \
}
info_t my_info = INFO_INIT;
/**
 * struct builtin - structure containing strings and related function
 * @func: related function
 * @type: command flag
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;
/*shell loop prototypes*/
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
/*parser.c proto*/
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
/*atoi.c*/
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
/*environ.c*/
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
/*builtin.c prototypes*/
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
/**builtin1.c*/
int _myhistory(info_t *);
int _myalias(info_t *);
/*exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
#endif /* _SHELL_H_ */

