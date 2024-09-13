#include <stdio.h>
#include <stdlib.h>

#include "kshell.h"

void kshell_loop() {
    char *input;
    char *prompt = "kshell> ";

    do {
        printf("%s", prompt);
        // Read the input from the user
        input = kshell_read_ln();
    
        printf("Echo: %s\n\n", input);
        // Parse the input
        // kshell_parse();

        // Execute the command
        // kshell_exec();
    } while (1);
    
}

void kshell_init() {
    // Initialize the shell
    // As of now, this function does nothing
    // In the future, this function will
    // initialize the shell using a
    // configuration file
    printf("Initializing the shell...\n\n");
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
            buffer = realloc(buffer, buffer_size);
            
            if (!buffer) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }
    }

}

void kshell_parse();

void kshell_exec();

void kshell_cleanup();
