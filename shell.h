#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

/* reading, executing command */
char *input(void);
int exe(char *const args[], char *prgrm);
int _split(const char *command, char *args[]);
void run_shell(const char *command, char *prgrm);


/* string manipulating */
int lenofstr(char const *string);
int cmpnstr(const char *string1, const char *string2, size_t n);
char *cpynstr(char *dest, const char *src, size_t n);
char *catnstr(char *dest, const char *src, size_t n);
char *chrstr(const char *string, int c);
char *dupstr(const char *string);

/*environment , path handling*/
extern char **environ;
int check_cur_dir(const char *command, char *const args[]);
int search_in_path(char *const args[]);
int handle_path(char *const args[]);
char *_getenv(const char *name);
void print_env(void);

#endif
