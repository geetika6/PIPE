#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

	pid_t pid;
        int rfd,wfd;
	char operator='+';
        struct data
        {
          int first,second;
	  char operator;
        }data_to_send;
	struct data *wdata;
        wdata=&data_to_send;
        wdata->first=2;
        wdata->second=3;
        wdata->operator='-';
       
	printf("argv[0]=%s\n",argv[0]);
	printf("argv[1]=%s\n",argv[1]);
	printf("argc=%d\n",argc);
        rfd=atoi(argv[0]);
        wfd=atoi(argv[1]);
	printf("rfd=%d\n",rfd);
	printf("wfd=%d\n",wfd);
        //write(wfd,"file",strlen("file"));
        write(wfd,wdata,sizeof(data_to_send));
}

