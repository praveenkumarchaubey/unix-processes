#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid,i;
    int status;
    if((pid=fork())==0)
    {
        if((pid=fork())>0)
            exit(10);
        sleep(1);
        printf("Second Child, parent Id =%d\n",getppid());
        exit(0);
    }
    i=wait(&status);
    printf("My Child with pid %d exited with status %d\n",i,WEXITSTATUS(status));
}

