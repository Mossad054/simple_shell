#include "shell.h"
#include <stdio.h>

void executeCommand(char *command, char **env);

void processInput(char *input)
{
    int i = 0;
    while (input[i])
    {
        if (input[i] == '\n')
            input[i] = 0;
        i++;
    }

  
    executeCommand(input, NULL);
}

