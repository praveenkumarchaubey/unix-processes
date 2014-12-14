/*Write a program that uses an “exec()” system call to execute a program given to it through command line.  For example if the name of your executable is “myexecutable” then if you invoke as follows: “myexecutable mycmd a b” then “mycmd” will be executed with command line parameters “a” & “b” by the program “myexecutable” (Note: “mycmd” may be any standard unix program or a program created by you)*/

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
      	execvp(argv[1],&argv[1]);
        return(0);
}

