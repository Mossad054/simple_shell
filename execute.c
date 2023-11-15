#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void executeCommand(char *command, char **env)
{
    pid_t child_pid;

    char **argv = malloc(2 * sizeof(char *));
    if (argv == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

   
    argv[0] = command;
    argv[1] = NULL;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        if (execve(argv[0], argv, env) == -1)
        {
            perror("execve");
            write(STDOUT_FILENO, "No such file or directory\n", 26);
            exit(EXIT_FAILURE);
        }
        else
        {
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        int status;
        wait(&status);

      
        free(argv);
    }
}

