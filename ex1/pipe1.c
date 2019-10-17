#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFFER 256

int main(void)
{
	char msg[BUFFER];
	int fd[2];
	int pid;

	/* cria um pipe */

	if(pipe(fd)<0)
	{
		perror("pipe");
		return -1;
	}
	
	/* cria o proesso filho */
	pid = fork();
	
	if(pid){
		char *hello = "\nCauan Siqueira\nMarlon Dantas\nMilena Ribeiro";
		
		close(fd[0]);
		
		write(fd[1],hello,strlen(hello)+1);
		
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
	
		read(fd[0], msg, sizeof msg);
		
		printf("Grupo: %s\n", msg);

		close(fd[0]);
	}

	return 0;
}
