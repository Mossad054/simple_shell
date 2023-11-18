#include "shell.h"
/*
* handle_fork_error -func to handle errors fork
* @command -charcter string
* */
void handle_fork_error(char *command)
{
perror("Fork error");
free(command);
exit(EXIT_FAILURE);
}
/*
* handle_exec_error- func to handle execution of errors
* @command -charcter string
* */
void handle_exec_error(char *command)
{
perror("Exec error");
free(command);
exit(EXIT_FAILURE);
}
/*
* wait_for_child -funn for waiting for child process
* @pid_t -child process indentifier
*/
void wait_for_child(pid_t child_pid)
{
int status;
waitpid(child_pid, &status, 0);
}


