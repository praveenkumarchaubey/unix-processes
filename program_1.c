#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    printf("hello\n");
    printf("...........my id is %d",getpid());
    pid=fork();
    printf("\nhello again\n");
    if(0==pid)
    {
        printf("child id is %d and parent id is %d\n",getpid(),getppid());
    }
    else
    {
        printf("....id is......%d\n",getpid());
    }
    printf("good bye\n");
    return(0);
}
