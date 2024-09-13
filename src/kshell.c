#include <stdio.h>
#include <stdlib.h>

#include "kshell.h"

void kshell_loop() {
    char *input;
    char *prompt = "kshell> ";

    do {
        printf("%s", prompt);
        // Read the input from the user
        kshell_read_ln(input);
    
        printf("input: %s\n", input);
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

void kshell_read_ln(char *input) {
    // Read user input and store it in a buffer
    int buffer_position = 0;
    int c;
    char *buffer = malloc(sizeof(char) * INPUT_BUFFER_SIZE);
    
    if (!buffer) {
        perror("calloc");
        exit(EXIT_FAILURE);
    } 

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[buffer_position] = '\0';
            break;
        }

        buffer[buffer_position] = c;
        buffer_position++;
    }

    // TODO: Handle buffer overflow vuln be dynamically resizing buffer

    input = buffer;
}

void kshell_parse();

void kshell_exec();

void kshell_cleanup();
