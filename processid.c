#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
*process_id -child process identifier
 * process_ppid - parent process identifier
 * main - entry point that always is void
* Return: 0 always
*/
int main(void)
{
	pid_t process_id;
	pid_t process_ppid;


	process_id = getpid();
	process_ppid = getppid();


	printf("My child process pid is %u\n", process_id);
	printf("My process parent ppid is %u\n", process_ppid);

	return (0);


}

