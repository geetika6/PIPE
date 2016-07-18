#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{

	pid_t pid;
        char *message;
        int no,exit_code;
	pid=fork();
	if (pid==0)
	{
		no=5;
		printf("child process=%d\n",getpid());
		message="This is child";
                exit_code=5;
	}
        else
        {
		no=3;
		printf("parent process=%d\n",getpid());
		message="This is parent";
                exit_code=0;
        }
        for(;no>0;no--)
        {
          puts(message);
          
          sleep(1);
        }
        if(pid!=0)
        {
		int stat_val;	
		pid_t child_pid;
		child_pid=wait(&stat_val);
		printf("child has finished PID=%d\n",child_pid);
		if(WIFEXITED(stat_val))
   			printf("child exited with code=%d\n",WEXITSTATUS(stat_val));
		else
   			printf("child terminated abnormally\n");
	
	}
 	exit(exit_code);

}
