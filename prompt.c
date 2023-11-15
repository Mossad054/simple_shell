#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void prompt(char **env)
{
    char *string = NULL;
    int i, status;
    size_t n = 0;
    ssize_t num_char;
    pid_t child_pid;
    char *argv[] = {NULL, NULL};
    bool interactive = isatty(STDIN_FILENO);

    while (1)
    {
        if (interactive)
        {
            write(STDOUT_FILENO, "Myshell$ ", 9);

            num_char = getline(&string, &n, stdin);
            if (num_char == -1)
            {
                free(string);
                exit(EXIT_FAILURE);
            }
            i = 0;
            while (string[i])
            {
                if (string[i] == '\n')
                    string[i] = 0;
                i++;
            }
        }
        else
        {
            num_char = getline(&string, &n, stdin);
            if (num_char == -1)
            {
                free(string);
                exit(EXIT_SUCCESS);
            }
        }

        argv[0] = string;
        child_pid = fork();

        if (child_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
            {
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
            wait(&status);
        }
    }
}

