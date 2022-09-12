#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX_LOOP_INDEX 15

int main()
{
    int index;
    for(index=0; index<MAX_LOOP_INDEX; index++)
    {
        if(fork()==0)
        {
            printf("Child Process %d\n",getpid());
            exit(index);
        }
    }
    sleep(10);
    printf("PARENT EXITING WITH PROCESS ID =%d",getpid());

}

