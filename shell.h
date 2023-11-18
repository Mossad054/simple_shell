
#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>


void print_prompt(bool interactive);
char *read_input();
void trim_newline(char *str);
void execute_command(char *command, char **env);
void handle_fork_error();  
void handle_exec_error(); 
void wait_for_child(pid_t child_pid);
void prompt(char **env);
#endif /* SHELL_H */

