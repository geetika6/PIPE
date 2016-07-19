#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

	pid_t pid;
        int rfd,wfd;
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
       
        rfd=atoi(argv[0]);
        wfd=atoi(argv[1]);
        //write(wfd,"file",strlen("file"));
        write(wfd,wdata,sizeof(data_to_send));
}

