#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t  pid      = 0;
    int    status   = 0;
    int    lindex   = 0;
    int    nopipes  = 0;
    int    cmdcount = 0;
    int    argcount = 0;
    int    buffsize = 64;

    char * pstr     = NULL;
    char * p_token  = NULL;
    char * cmds[16];
    char * arg[16][16];

    char   inputbuffer[64];
    int    pipefd[16][2];

    while (1)
    {
        lindex   = 0;
        cmdcount = 0;
        buffsize = 63;
        pstr     = inputbuffer;
        write(1, "MYSHELL>", 8);
        buffsize = read(0, inputbuffer, buffsize);
        inputbuffer[buffsize] = '\0';

        if (buffsize > 0)
        {
            p_token = strsep(&pstr, "|\n");
            while(p_token)
            {
                cmds[cmdcount++] = p_token;
                p_token = strsep(&pstr, "|\n");
            }
            cmdcount--;
            nopipes = cmdcount - 1;
            while (lindex < cmdcount)
            {
                argcount = 0;
                p_token = strtok(cmds[lindex], " \n|");
                while (1)
                {
                    arg[lindex][argcount++] = p_token;
                    if (NULL == p_token)
                        break;
                    p_token = strtok(NULL, " \n|");
                }
                lindex++;
            }
            if (1 == cmdcount)  /*simple command*/
            {
                pid = fork();
                if (0 == pid)
                {
                    execvp(arg[0][0], arg[0]);
                }
                else if (0 < pid)
                {
                    wait(&status);
                }
            }
            else if (1 < cmdcount) /*pipes*/
            {
                //create pipes
                for (lindex = 0;lindex < nopipes; lindex++)
                {
                    pipe(pipefd[lindex]);
                }
                //create processes
                for (lindex = 0;lindex < cmdcount; lindex++)
                {
                    int liter = 0;
                    pid = fork();
                    if (0 == pid)
                    {
                        if (0 == lindex)
                        {
                            close(1);
                            dup(pipefd[lindex][1]);
                            for (liter = 0;liter < nopipes; liter++)
                            {
                                close(pipefd[liter][0]);
                                close(pipefd[liter][1]);
                            }
                            execvp(arg[lindex][0], arg[lindex]);
                        }
                        else if ((0 < lindex) && (lindex < cmdcount-1))
                        {
                            close(0);
                            close(1);
                            dup(pipefd[lindex-1][0]);
                            dup(pipefd[lindex][1]);
                            for (liter = 0;liter < nopipes; liter++)
                            {
                                close(pipefd[liter][0]);
                                close(pipefd[liter][1]);
                            }
                            execvp(arg[lindex][0], arg[lindex]);
                        }
                        else
                        {
                            close(0);
                            dup(pipefd[lindex-1][0]);
                            for (liter = 0;liter < nopipes; liter++)
                            {
                                close(pipefd[liter][0]);
                                close(pipefd[liter][1]);
                            }
                            execvp(arg[lindex][0], arg[lindex]);
                        }
                    }
                }
                for (lindex = 0;lindex < nopipes; lindex++)
                {
                    close(pipefd[lindex][0]);
                    close(pipefd[lindex][1]);
                }
                for (lindex = 0;lindex < cmdcount; lindex++)
                {
                    wait(&status);
                }
            }
        }
    }
    return 1;
}
