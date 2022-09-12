#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execl("./pgm2","pgm2", NULL);
        printf("i am child: %u\n", getpid());
        printf("my parent is: %u\n", getppid());

    }
    else
    {
        printf("i am parent: %u\n", getpid());
        printf("my child is: %u\n", pid);

    }
    return 0;
}

