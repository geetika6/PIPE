#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

        int pipefd[2];
        int pipefd1[2];
        //char rfd[4],wfd[4],buf[100];
        char *rfd=malloc(sizeof(char));
        char *wfd=malloc(sizeof(char));
        int nbytes;
        struct data
        {
          int first,second;
	  char operator;
        }data_to_send;
	struct data *rdata;
        rdata=&data_to_send;
	pid_t pid;
        if (pipe(pipefd)==-1)
        {
		printf("error in pipe");
        }
        sprintf(rfd,"%d",pipefd[0]);
		printf("rfd =%s\n",rfd);
        sprintf(wfd,"%d",pipefd[1]);
		printf("wfd =%s\n",wfd);
	pid=fork();
	if (pid==0)
	{
		printf("child process=%d\n",getpid());
             	execl("/home/geet/Documents/c_prac/Linux-Device-Driver/Linux-Device-Driver/Process_management/pipe/PIPE/req_client",rfd,wfd,NULL);
                //execl("req_client",rfd,wfd,NULL);
		printf("hello");
	}
        else
        {

		printf("parent process=%d\n",getpid());
		sleep(1);
                //nbytes=read(pipefd[0],buf,100);
                nbytes=read(pipefd[0],rdata,sizeof(data_to_send));
		//printf("child process read value=%s\n",buf);
                if (pipe(pipefd1)==-1)
                {
	        	printf("error in pipe 2");
                }
                sprintf(rfd,"%d",pipefd1[0]);
                sprintf(wfd,"%d",pipefd1[1]);
	        printf("read_fd1=%s\n",rfd);
	        printf("write_fd1=%s\n",wfd);
	        pid=fork();
	        if (pid==0)
	        {
	        	printf("child process processing=%d\n",getpid());
	        	sleep(1);
                     	execl("/home/geet/Documents/c_prac/Linux-Device-Driver/Linux-Device-Driver/Process_management/pipe/PIPE/processing_client",rfd,wfd,NULL);
                        //execl("req_client",rfd,wfd,NULL);
	        	printf("hello");
	        }
                else
                {

	        	printf("parent process=%d\n",getpid());
	        	//printf("child process read value=%s\n",buf);
                	write(pipefd1[1],rdata,sizeof(data_to_send));
	        	sleep(1);
	        	sleep(1);
                }
	
        }

}
