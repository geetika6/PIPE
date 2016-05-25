#include <stdio.h>
#include <unistd.h>

int main()
{

        int pipefd[2];
        int pipefd1[2];
        char rfd[4],wfd[4],buf[100];
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
        sprintf(wfd,"%d",pipefd[1]);
	printf("read_fd=%s\n",rfd);
	printf("write_fd=%s\n",wfd);
	pid=fork();
        //#exec_val=execl("/home/geet/Documents/c_prac/LDD_Training/Process_management/req_client.c",rfd,wfd);
	if (pid==0)
	{
		printf("child process=%d\n",getpid());
             	execl("/home/geet/Documents/c_prac/LDD_Training/Process_management/req_client",rfd,wfd,NULL);
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
		printf("parent process read value=%d\n",rdata->first);
		printf("parent process read value=%d\n",rdata->second);
		printf("parent process read value=%c\n",rdata->operator);
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
                     	execl("/home/geet/Documents/c_prac/LDD_Training/Process_management/processing_client",rfd,wfd,NULL);
                        //execl("req_client",rfd,wfd,NULL);
	        	printf("hello");
	        }
                else
                {

	        	printf("parent process=%d\n",getpid());
	        	//printf("child process read value=%s\n",buf);
	        	printf("parent process write value=%d\n",rdata->first);
	        	printf("parent process write value=%d\n",rdata->second);
	        	printf("parent process write value=%c\n",rdata->operator);
                	write(pipefd1[1],rdata,sizeof(data_to_send));
	        	sleep(1);
	        	sleep(1);
                }
	
        }

}
