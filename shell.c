#include  "shell.h" 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
 *
 *
 */
int main(int argc, char** argv)

{
	(void)argv;

        if (argc == 1)
	{
		prompt(NULL);
	}
	return 0;
}

