#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>

int _execute(char *ac, struct stat *statbuf, char **envp);
bool check_file_status(char *path, struct stat *statbuf);
void handle_error(pid_t pid);
char **split_string(char *string, char delimiter, int *count);

#endif /* _MAIN_H */
