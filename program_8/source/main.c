#include"header.h"
int globalvar=6;
main()
{
        int localvar;
        pid_t pid;
        localvar=88;
        printf("BEFORE VFORK\n");
        pid=fork();
	if(pid!=0)
        {  
		sleep(2);
                printf("ERROR IN VFORK\n");
             //   exit(0);
        }
        else 
        {
                globalvar++;
                localvar++;
                exit(0);
        }
        printf("Parent process id = %d, global variable=%d, local variable=%d\n", getpid(), globalvar, localvar);
}



