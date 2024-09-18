#ifndef KSHELL_H
#define KSHELL_H

#define INPUT_BUFFER_SIZE 1024
#define TOKEN_BUFFER_SIZE 64
#define TOKEN_DELIMETER " \t\r\n\a"
#define DEFAULT_PROMPT "kshell> "

void print_prompt();
void kshell_loop();
void kshell_init();
char *kshell_read_input();
char **kshell_parse(char *line);
int kshell_start_process(char **args);
int kshell_exec(char **args);
void kshell_cleanup();

#endif
