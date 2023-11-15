#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(char **env);
void processInput(char *input);
void executeCommand(char *command, char **env);
#endif /* SHELL_H */
