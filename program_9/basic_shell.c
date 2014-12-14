#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	pid_t  pid      = 0;
	int    status   = 0;
	int    lcounter = 0;
	int    buffsize = 32;
	char   inputbuffer[32];
	char * p_token = NULL;
	char * arg[16];
	while (1) {
		lcounter = 0;
		buffsize = 32;
		write(1, "MYSHELL>", 8);
		buffsize = read(0, inputbuffer, buffsize);
		inputbuffer[buffsize] = '\0';
		if (buffsize > 0) {
			p_token = strtok(inputbuffer, " '\n'");
			arg[lcounter++] = p_token;
			while(p_token) {
				p_token = strtok(NULL, " '\n'");
				arg[lcounter++] = p_token;
				if (16 == lcounter)
					break;
			}
			pid = fork();
			if (0 == pid) {
				execvp(arg[0], arg);
			}
			else { 
				wait(&status);
			}
		}
	}
	return 1;
}
