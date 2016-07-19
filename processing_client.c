#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

	int pipefd[2];
	pid_t pid;
	int rfd,wfd;
	int nbytes,result;
	char operator;
	struct data
	{
		int first,second;
		char operator;
	}data_to_send;
	struct data *rdata;
	rdata=&data_to_send;

	rfd=atoi(argv[0]);
	wfd=atoi(argv[1]);
	nbytes=read(rfd,rdata,sizeof(data_to_send));
	switch(rdata->operator)
	{
		case '+':
			result=rdata->first + rdata->second;
			break;

		case '-':
			result=rdata->first - rdata->second;
			break;

		case '*':
			result=rdata->first * rdata->second;
			break;

		case '/':
			result=rdata->first / rdata->second;
			break;
	}

	printf("In processing client result=%d\n",result);
}

