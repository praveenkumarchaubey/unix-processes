/*Write a program that, forks to create a child process. The child exits with an exit status of 10 and the parent waits for the death of the child. Display the PID & PPID of both processes and let the parent display the child's exit status. (Use fork, exit, wait)*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	int status = 10;
	
	pid = fork();
	if(pid == 0)
	{
		printf("i am child: %u\n", getpid());
		printf("my parent is: %u\n", getppid());
		printf("i am exiting now\n\n");
		exit(status);
	}
	else
	{
		printf("i am parent: %u\n", getpid());
		printf("my child is: %u\n", pid);
		printf("i am waiting for my child to exit\n\n");
		wait(&status);
		printf("my child exited with a status: %d\n", WEXITSTATUS(status));
		printf("Now i am exiting\n\n");
	}
	return 0;
}

