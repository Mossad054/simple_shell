
#include "shell.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*
* print_prompt -func for printing promt
*@interactive -interactive string
*/
void print_prompt(bool interactive)
{
if (interactive)
{
write(STDOUT_FILENO, "Myshell$ ", 9);
}
}

char *read_input()
{
char *string = NULL;
size_t n = 0;
ssize_t num_char;

num_char = getline(&string, &n, stdin);

if (num_char == -1)
{
free(string);
return NULL;/*parenthis used*/
}

return string;/* parenthis not required*/
}
/*
* trim_newline- func for new line output
* @str -string
*/
void trim_newline(char *str)
{
int i = 0;
while (str[i])
{
if (str[i] == '\n')
{
str[i] = 0;
return;
}
i++;
}
}
/*
* execute_command -func for executing commnad
* @command - character string
* @env -environment variable
*/
void execute_command(char *command, char **env)
{
pid_t child_pid = fork();

if (child_pid == -1)
{
handle_fork_error();
}

if (child_pid == 0)
{
char **argv = (char **)malloc(2 * sizeof(char *));
if (argv == NULL)
{
handle_fork_error();
}

argv[0] = command;
argv[1] = NULL;

if (execve(command, argv, env) == -1)
{
const char *error_message = "No such file or directory\n";
write(STDERR_FILENO, error_message, strlen(error_message));
free(command);
free(argv);
exit(EXIT_FAILURE);
}

free(argv);


exit(EXIT_FAILURE);
} else
{
int status;
waitpid(child_pid, &status, 0);
}
}
/*
* prompt -func for promting character
* @env -envionment variable
*/
void prompt(char **env)
{
char *string;
bool interactive = isatty(STDIN_FILENO);

while (1)
{
print_prompt(interactive);

string = read_input();

if (string == NULL)
{
if (interactive)
{
exit(EXIT_FAILURE);
}
else
{
return;
}
}

if (interactive)
{
trim_newline(string);
}

execute_command(string, env);

if (!interactive)
{
free(string);
return;
}
}
}

