#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    char buffer[30];
    char *token = NULL;
    char *arg[10];
    int count = 0;
    int read_size;
    while(1)
    {
        count = 0;
        write(1, "chaubey's shell->", 17);
        read_size = read(0,buffer,sizeof(buffer));
        buffer[read_size] = '\0';
        if(read_size > 0)
        {
            token= strtok(buffer," \n");
            arg[count++] =token;
            while(token)
            {
                token = strtok(NULL," \n");
                arg[count++] = token;
            }
            arg[count]= NULL;
            pid = fork();
            if(0==pid)
            {
                execvp(arg[0],arg);
            }
            else
            {
                wait(NULL);
            }
        }
    }
    return 0;
}
