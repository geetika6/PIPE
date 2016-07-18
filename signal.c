#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void ouch(int sig)
{
	printf("OUCH ! I got signal %d\n",sig);
	(void)signal(SIGINT,SIG_DFL);
}

void main()
{

	(void)signal(SIGINT,ouch);

	while(1)
	{
       		printf("Hello world\n");
       		sleep(1);
	}

}
