#include <stdio.h>
#include <unistd.h>

#ifndef BUILTINS_H
#define BUILTINS_H

extern char *kshell_builtin_names[];
extern int (*kshell_builtin_functions[]) (char **);

int kshell_number_of_builtins();
int kshell_cd(char **args);
int kshell_help(char **args);
int kshell_exit(char **args);

#endif
