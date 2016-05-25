#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

        int pipefd[2];
	pid_t pid;
        int rfd,wfd;
        int nbytes;
        struct data
        {
          int first,second;
	  char operator;
        }data_to_send;
	struct data *rdata;
        rdata=&data_to_send;
       
	printf("argv[0]=%s\n",argv[0]);
	printf("argv[1]=%s\n",argv[1]);
	printf("argc=%d\n",argc);
        rfd=atoi(argv[0]);
        wfd=atoi(argv[1]);
	printf("rfd=%d\n",rfd);
	printf("wfd=%d\n",wfd);
        //write(wfd,"file",strlen("file"));
        nbytes=read(rfd,rdata,sizeof(data_to_send));
	printf("process read first value=%d\n",rdata->first);
	printf("process read second=%d\n",rdata->second);
	printf("process read operator=%c\n",rdata->operator);
	printf("process read nbytes=%d\n",nbytes);
	printf("process sizeof =%d\n",sizeof(data_to_send));
}

