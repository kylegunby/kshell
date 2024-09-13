#ifndef KSHELL_H
#define KSHELL_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define INPUT_BUFFER_SIZE 1024

void kshell_loop();
void kshell_init();
char *kshell_read_ln();
void kshell_parse();
void kshell_exec();
void kshell_cleanup();
#endif
