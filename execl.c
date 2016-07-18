#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{

	pid_t pid,child_pid;
        char *message;
        int no,exit_code;
	pid=fork();
	if (pid==0)
	{
		no=5;
		printf("child process=%d\n",getpid());
		message="This is child";
                execlp("ps","ps","-ax",NULL);
                exit_code=5;
	}
        else
        {
		no=3;
		printf("parent process=%d\n",getpid());
		message="This is parent";
                exit_code=0;
                child_pid=wait(0);
		printf("parent process ends,child process id =%d\n",child_pid);
        }
 	exit(exit_code);

}
