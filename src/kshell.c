#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "kshell.h"
#include "builtins.h"

void kshell_loop() {
    char *input;
    char **args;
    int status;

    do {
        printf("kshell> ");
        input = kshell_read_ln();
        args = kshell_parse(input);
        status = kshell_exec(args);
    } while (1);
    
}

void kshell_init() {
    // Initialize the shell
    // As of now, this function does nothing
    // In the future, this function will
    // initialize the shell using a
    // configuration file
    //printf("Initializing the shell...\n\n");
}

char *kshell_read_ln() {
    // Read user input and store it in a buffer
    int buffer_size = INPUT_BUFFER_SIZE;
    int buffer_position = 0;
    int c;
    char *buffer = malloc(sizeof(char) * buffer_size);
    
    if (!buffer) {
        perror("calloc");
        exit(EXIT_FAILURE);
    } 

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[buffer_position] = '\0';
            return buffer;
        }

        
        buffer[buffer_position] = c;
        buffer_position++;

        if (buffer_position >= buffer_size) {
            buffer_size += INPUT_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size * sizeof(char *));
            
            if (!buffer) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **kshell_parse(char *input) {
    int buffer_size = TOKEN_BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(buffer_size * sizeof(char *));
    char *token;

    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    
    token = strtok(input, TOKEN_DELIMETER);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position > buffer_size) {
            buffer_size += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));

            if (!tokens) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMETER);
    }

    tokens[position] = NULL;
    return tokens;
}


int kshell_start_process(char **args) {
    pid_t pid, wpid;
    int status;

    // To start a child process, we must fork the parent
    pid = fork();
    if (pid == 0) {
        // The process is cloned, and the child process recieves a 0, so this
        // branch is where the child process (if created successfully)
        // Continues in our program. So this logic is being executed
        // by the child process while the parent continues to the
        // else clause at the bottom
        //
        // execvp takes the name of the command, and a vector or arguments
        // it then passes the name of the command and looks for it on the 
        // system, and if there's an error, returns a -1.
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        // Error forking the parent process
        perror("fork");
    } else {
        // This is where the parent process is executed
        do {
            // waitpid waits for the specified pid status to change
            // in this case, we are waiting for the child process
            // to complete and return a status
            //
            // We wait for the process to exit or be killed
            // we aren't handling any specifics
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int kshell_exec(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    for (int i = 0; i < kshell_number_of_builtins(); i++) {
        if (strcmp(args[0], kshell_builtin_names[i]) == 0)
            return (*kshell_builtin_functions[i])(args);
    }

    return kshell_start_process(args);
}

