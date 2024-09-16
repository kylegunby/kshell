#include <stdio.h>
#include <unistd.h>

#ifndef BUILTINS_H
#define BUILTINS_H

int kshell_cd(char **args);
int kshell_help(char **args);
int kshell_exit(char **args);
int kshell_number_of_builtins();

char *kshell_builtin_names[] = {
    "cd",
    "help",
    "exit",
};

int (*kshell_builtin_functions[]) (char **) = {
    &kshell_cd,
    &kshell_help,
    &kshell_exit,
};

int kshell_number_of_builtins() {
    return sizeof(kshell_builtin_names) / sizeof(char *);
}

int kshell_cd(char **args) {
    if (args[1] == NULL) {
        // TODO: implement change to home directory
        fprintf(stderr, "Kshell: cd requires an argument. Env vars not implemented.\n");
        return 1;
    } else {
        if (chdir(args[1]) != 0) {
            perror("chdir");
            return 1;
        }
    }
    return 0;
}

int kshell_help(char **args) {
    printf("Kyle's Shell (kshell)\n");
    printf("Type a command and press enter to run it\n");
    printf("The following is a list of built in functions:\n");

    for (int i = 0; i < kshell_number_of_builtins(); i++) {
        printf("  %s\n", kshell_builtin_names[i]);
    }

    return 0;
}

int kshell_exit(char **args) {
    return 0;
}

#endif
